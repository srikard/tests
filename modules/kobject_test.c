#include <linux/module.h>
#include <linux/init.h>
#include <asm/errno.h>
#include <linux/kobject.h>

static int __init kobject_test_init(void)
{
	struct kobject kobj;
	int i;

	pr_info("kobject_test module loaded\n");
	memset(&kobj, 0, sizeof(struct kobject));
	kobj.name=0xffffffffff;
	for (i=0; i<10; i++) {
		kobject_put(&kobj);
		kobject_get(&kobj);
	}
	return 0;
}

static void __exit kobject_test_exit(void)
{
	pr_info("kobject_test module unloaded\n");
}
module_init(kobject_test_init);
module_exit(kobject_test_exit);

MODULE_DESCRIPTION ("kobject_test");
MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("Srikar Dronamraju");

