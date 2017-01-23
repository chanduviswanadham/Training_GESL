#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/highmem.h>

MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 0
#define NR_DEVS 1
#define LOWMEM 0x38000000
#define VIR_OFFSET 0xc0000000

int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *, unsigned int, unsigned long);

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

long myIoctl(struct file *fp, unsigned int arg1, unsigned long glo_var)
{
	struct task_struct *task = current;
	unsigned long *pt = NULL;
	unsigned long *pf = NULL;
	extern struct page *mem_map;
	
	unsigned long pgdind;	//to store the pgd index
	unsigned long ptind;	//to store the pt index
	unsigned long pgind;	//to store the pageframe index
	pgd_t *pgd_ptr = task -> mm -> pgd;

	printk("catched global variable address: %ld\n", glo_var);	

	pgdind = (((unsigned long)glo_var) >> 22);
	ptind = ((((unsigned long)glo_var) << 10) >> 22);
	pgind = ((unsigned long)glo_var) & 0x00000FFF;

	printk("pgdind %lx\n", pgdind);
	printk("ptind %lx\n", ptind);
	printk("pgind %lx\n", pgind);

	printk("pgd table base %p\n", pgd_ptr);
	printk("pgd after adding the index:%p\n", ((char *)(pgd_ptr)) + pgdind);
	
	if(pgd_ptr[pgdind].pgd < LOWMEM) {	//checking wether it is in LOWMEM
		pt = (unsigned long *)((((pgd_ptr[pgdind].pgd) >> 12) << 12)
															 + VIR_OFFSET);
	} else {
		pt = (unsigned long *)kmap(&mem_map[(pgd_ptr[pgdind].pgd) >> 12]);
	}

	printk("pt table base %p\n", pt);
	printk("pt after adding the index:%p\n", ((char *)pt) + ptind);
	
	if(pt[ptind] < LOWMEM) {
		pf = (unsigned long *)(((pt[ptind] >> 12) << 12) + VIR_OFFSET);
	} else {
		pf = (unsigned long *)kmap(&mem_map[ pt[ptind] >> 12 ]);
	}

	*(((char *)pf) + pgind) = 15;

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

