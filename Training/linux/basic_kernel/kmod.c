#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>

// geting the license from the GPL
MODULE_LICENSE("Dual BSD/GPL");

//   constants 
#define FIRST_MINOR 0
#define NR_DEVS 1

//function declarations for syscall definations 

int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *filep1, unsigned int t, unsigned long p);

//Initialization routines 

static int myInit(void);
static void myExit(void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myIoctl
};
int chandu = 10; 	//exporting

EXPORT_SYMBOL(chandu);
//Global variable

char *devname;	//contains device name
int majNo;		//stores the major number
static dev_t mydev;		//encodes major number and minor numbers 
struct cdev *my_cdev;		//holds character device driver

module_param(devname, charp, 0000);

//class and device structure

static struct class *mychar_class;
static struct device *mychar_device;

//myopen fucntion

int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "Open successful\n");
	return 0;
}

//myrelease function

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

long myIoctl(struct file *filep1, unsigned int pid, unsigned long p)
{
	struct task_struct *task = NULL;
	struct module *mod;
//	struct mm_struct *m_mm;
//	struct vm_area_struct *v_add = NULL;
	task = current;		
//	task = find_task_by_pid(pid);
//	v_add = task -> mm -> mmap;
	mod = THIS_MODULE;
	
	printk(KERN_INFO "in own myIoctl function\n");
	printk(KERN_INFO "pid from task_struct:%d\n", task -> pid);
	printk(KERN_INFO "comm from task_struct:%s\n", task -> comm);
	printk (KERN_INFO "kernel module name :%s", mod -> name);
	printk (KERN_INFO "myIoctl pid from getpid():%d\n", pid);
//	printk (KERN_INFO "values of vm_start is : %p", v_add -> vm_start );
//	printk (KERN_INFO "values of vm_end is : %p", v_add -> vm_end);
	return 0;
}

/*init function of kernel modules*/

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing character device\n");

	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0) {
		printk(KERN_INFO "Device number allocation failed: %d\n", status);
		goto err;
	}

	printk(KERN_INFO "Major number allocated = %d\n", MAJOR(mydev));
	my_cdev = cdev_alloc();
	if(my_cdev == NULL) {
		printk(KERN_INFO "cdev_alloc failed \n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);
	my_cdev -> owner = THIS_MODULE;

	status = cdev_add (my_cdev, mydev, NR_DEVS);
	if(status) {
		printk(KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}
	
	//create a class and an entry in sysfs

	mychar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed \n");
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

/*cleaning function*/

static void myExit(void)
{
	printk(KERN_INFO "Exiting the character driver \n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}


module_init(myInit);//macros which is where to start
module_exit(myExit);	//macros which is where is clean function

