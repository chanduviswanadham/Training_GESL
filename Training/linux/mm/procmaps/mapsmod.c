#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/mount.h>

MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 0
#define NR_DEVS 1

int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *, unsigned int, unsigned long);
void mypath(struct dentry *);

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

long myIoctl(struct file *fp, unsigned int arg1, unsigned long arg2)
{
	struct vm_area_struct *vmptr= NULL;
	struct task_struct *pcbptr = current;
	unsigned long ino;
	unsigned int rdev;
	struct dentry *dn = NULL;

	vmptr = ((pcbptr -> mm) -> mmap);

	while(vmptr != NULL) {
		
		printk(KERN_INFO "%08lx-%08lx ", (vmptr -> vm_start), (vmptr -> vm_end));
	
		if((vmptr -> vm_flags) & 0x00000001) {
			printk("r");
		} else {
			printk("-");
		}

		if((vmptr -> vm_flags) & 0x00000002) {
			printk("w");
		} else {
			printk("-");
		}

		if((vmptr -> vm_flags) & 0x00000004) {
			printk("x");
		} else {
			printk("-");
		}

		if((vmptr -> vm_flags) & 0x00000008) {
			printk("s ");
		} else {
			printk("p ");
		}

		if(vmptr -> vm_file != NULL) {
			printk("%05lx000 ", (vmptr -> vm_pgoff));

			rdev = vmptr -> vm_file -> f_path.mnt -> mnt_sb -> s_dev;
			printk("%02x:%02x ", (rdev >> 20), (rdev & 0x000FFFFF));

			ino = vmptr -> vm_file -> f_path.dentry -> d_inode -> i_ino;
			printk("%ld ", ino);

			dn = vmptr -> vm_file -> f_path.dentry;
			mypath(dn);

			printk("\n");
		} else {
			printk("00000000 ");
			printk("00:00 ");
			printk("0 ");
			if(pcbptr -> mm -> start_brk == vmptr -> vm_start) {
				printk("[heap]");
			} else if(pcbptr -> mm -> start_stack == vmptr -> vm_start) {
				printk("[stack]");
			}

			printk("\n");

		}

		vmptr = vmptr -> vm_next;
	}

	return 0;
}

void mypath(struct dentry *dn)
{
	if(strcmp(dn -> d_name.name, "/") != 0) {
		mypath(dn -> d_parent);
		printk("/%s", dn -> d_name.name);
	}
	
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

