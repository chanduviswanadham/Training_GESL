#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<linux/fdtable.h>

MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 0
#define NR_DEVS 1

int myOpen(struct inode *, struct file *);
int myRelease(struct inode *, struct file *);
long myIoctl(struct file *, unsigned int, unsigned long);  

static int myInit (void);
static void myExit (void);

struct file_operations fops = {
		.owner = THIS_MODULE,
		.open = myOpen,
		.release = myRelease,
		.unlocked_ioctl = myIoctl
};

char *devname;
int majNo;
static dev_t mydev;
struct cdev *my_cdev;
 
module_param(devname, charp, 0000);

static struct class *mychar_class;
static struct device *mychar_device;

int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "Open successful\n");
	return 0;
}

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing Character Device\n");
	
	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0)
	{
		printk(KERN_NOTICE "Device numbers allocation failed:%d\n", status);
		goto err;
	}

	printk(KERN_INFO "Major number allocated = %d\n", MAJOR(mydev));
	my_cdev = cdev_alloc();
	if(my_cdev == NULL) {
		printk(KERN_ERR "cdev_alloc failed\n");
		goto err_cdev_alloc;
	}
	cdev_init(my_cdev, &fops);
	my_cdev -> owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, NR_DEVS);
	if(status) {
		printk(KERN_ERR "cdev_add failed\n");
		goto err_cdev_add;
	}
	mychar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(mychar_class)) {
		printk(KERN_ERR "cdev_create() failed\n");  
		goto err_class_create;
	}

  	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);                           
    if(IS_ERR(mychar_device)) {                                                  
        printk(KERN_ERR "cdev_create() failed\n");                              
        goto err_device_create;                                                  
    }    
	return 0;

err_device_create:
	class_destroy(mychar_class);

err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree(my_cdev);

err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);

err:
	return ret;
}
static void myExit(void)
{
	printk(KERN_INFO "Exiting the Character Driver\n");  		
	
	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

long myIoctl(struct file *fd, unsigned int a, unsigned long text_fd)
{
	struct task_struct *tsk = current;
	//struct task_struct *task = find_task_by_vpid(a);
#if 0
	printk(KERN_INFO "unlockd_ioctl\n");
	printk(KERN_INFO "pid is %d\n", task -> pid);
	printk(KERN_INFO "executable path %s\n", tsk -> comm);
	printk(KERN_INFO "module is %s\n", mod -> name);

	while(tsk -> mm -> mmap -> vm_next != NULL) {
		printk(KERN_INFO "Starting address is %x and End address is %x\n", 
		tsk -> mm -> mmap -> vm_start, tsk -> mm -> mmap -> vm_end);
		tsk -> mm -> mmap = tsk -> mm -> mmap -> vm_next; 
	}
#endif
	printk(KERN_INFO "tsk -> mm 0x%08x\n", tsk -> mm);
	printk(KERN_INFO "tsk -> mm -> maps 0x%08x\n", tsk -> mm -> mmap);
	

	return 0;
}
module_init(myInit);
module_exit(myExit);

