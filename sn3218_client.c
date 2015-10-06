#include <linux/i2c.h>

static struct i2c_device_id sn3218_idtable[] = {
    { "sn3218", 0},
    {}
};

static const struct dev_pm_ops sn3218_pm_ops = {
    .suspend = sn3218_suspend,
    .resume = sn3218_resume,
};

MODULE_DEVICE_TABLE(i2c, sn3218_idtable);

static struct i2c_driver sn3218_driver = {
    .driver = {
        .owner = THIS_MODULE,
        .name = "sn3218",
        .pm = &sn3218_pm_ops,
    },
    .id_table = sn3218_idtable,
    .probe = sn3218_probe,
    .remove = sn3218_remove,
};

int sn3218_read_value(struct i2c_client *client, u8 reg)
{
    return i2c_smbus_read_byte_data(client, reg);
}

int sn3218_write_value(struct i2c_client *client, u8 reg, u8 value)
{
    return i2c_smbus_write_byte_data(client, reg, value);
}

static int sn3218_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    return 0;
}

static int sn3218_remove(struct i2c_client *client)
{
    return 0;
}

static int __init sn3218_init( void )
{
    return i2c_add_driver(&sn3218_driver);
}
module_init(sn3218_init);

static void __exit sn3218_exit( void )
{
    i2c_del_driver(&sn3218_driver);
}
module_exit(sn3218_exit);

MODULE_AUTHOR("Kyle Zhou <kyle.zhou@live.com>");
MODULE_DESCRIPTION("Driver for SN3218 LED PWM controller");
MODULE_LICENSE("GPL v2");
