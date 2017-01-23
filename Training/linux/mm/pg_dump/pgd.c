#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/highmem.h>

MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 0
#define NR_DEVS 1
#define ENTRIES 1204

//#define LAST_NIBBLE(pt) (((pt)>> 12) << 12) 

int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *filep1, unsigned int t, unsigned long p);

static int myInit(void);
static void myExit(void);

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

long myIoctl(struct file *filep1, unsigned int pid, unsigned long p)
{
	struct task_struct *task = current;
	pgd_t *ptr = task -> mm -> pgd;
	unsigned long *pt_vir = NULL;
	extern struct page *mem_map;

	int i;
	int j;

	short count = 0;
	int ker_count = 0;
	int usr_count = 0;
	int low_mem = 0;
	int high_mem = 0;
	
	
	printk(KERN_INFO "**************************************PGD info******************************************************\n");

	for (i = 0; i < 1024; i++) {		//PGD table have 1204 entires

		if (ptr[i].pgd) { //only for valid address i.e non null

			( i > 768 ) ? ker_count++ : usr_count++;
			
			printk (KERN_INFO "index : { %d } PGD : %08lx\n", i, ((ptr[i].pgd) >> 12 ) << 12);
			pt_vir = NULL;

			if ((ptr[i].pgd) < 0x38000000) {			// checking whether that is belogs to low mem

				pt_vir = (unsigned long *) ((((ptr[i].pgd) >> 12 ) << 12) + 0xc0000000); // getting VA
				low_mem++;
			
			} else {
				
				pt_vir = (unsigned long *) kmap(mem_map + ((ptr[i].pgd) >> 12));
				high_mem++;
			
			}
				
			for (j = 0; j < 1024; j++) {
					
				if (*pt_vir) {	
				
					printk (KERN_INFO "\t\tPT:%08lx\n", *pt_vir);
				
				}
				
				pt_vir++;
			
			}
			
			count++;
		}
		
	}
	
	printk (KERN_INFO "count : %hd\n", count);

	return 0;
}
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

static void myExit(void)
{
	printk(KERN_INFO "Exiting the character driver \n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

module_init(myInit);
module_exit(myExit);

