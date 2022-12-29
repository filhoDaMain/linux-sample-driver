#include <linux/module.h>
#include <linux/kernel.h>

// User defined includes
#include <basicmath/add.h>

#define DRIVER_NAME "hellow"

// __init attribute will cause the initialization function to be discarded
// and its memory reclaimed after initialization is complete.
// Only works for built-in drivers; it has no effect on loadable modules.
int __init hello_init(void)
{
    int a = 2;
    int b = 3;
    pr_info("%s: Hello World!\n", DRIVER_NAME);
    pr_info("%s: %d + %d is %d\n", DRIVER_NAME, a, b, add_integers(a, b));
    return 0;
}

// __exit attribute causes the omission of the marked function when the driver 
// is not built as a module.
// Only works for built-in drivers; it has no effect on loadable modules.
void __exit hello_exit(void)
{
    pr_info("%s: Goodbye World!\n", DRIVER_NAME);
}

module_init(hello_init);
module_exit(hello_exit);


MODULE_AUTHOR("Andre Temprilho");
MODULE_DESCRIPTION("A Linux kernel sample driver of hello-world kind");
MODULE_LICENSE("GPL");