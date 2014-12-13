#include <linux/module.h>
#include <linux/slab.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/i2c.h>

static int __devinit sensorhub_probe(struct i2c_client *client,
                                   const struct i2c_device_id *id)
{
        printk("%s\n", __func__);
        return 0;
}

static int __devexit sensorhub_remove(struct i2c_client *client) 
{
        printk("%s\n", __func__);
        return 0;
}

static struct i2c_device_id sensorhub_idtable[] = {
        { "sensorhub", 0x48 },
        { }
};

MODULE_DEVICE_TABLE(i2c, sensorhub_idtable);

static struct i2c_driver sensorhub_driver = {
        .driver = {
                .owner  = THIS_MODULE,
                .name   = "sensorhub"
        },
        .id_table       = sensorhub_idtable,
        .probe          = sensorhub_probe,
        .remove         = __devexit_p(sensorhub_remove),
};


static int __init sensorhub_init(void)
{
        return i2c_add_driver(&sensorhub_driver);
}

static void __exit sensorhub_exit(void)
{
        i2c_del_driver(&sensorhub_driver);
}

module_init(sensorhub_init);
module_exit(sensorhub_exit);

MODULE_AUTHOR("Kwangwoo Lee <kwlee@mtekvision.com>");
MODULE_DESCRIPTION("TSC2007 TouchScreen Driver");
MODULE_LICENSE("GPL");

