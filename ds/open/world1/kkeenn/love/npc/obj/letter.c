inherit ITEM;
void create()
{       set_name("妙法的家信",({ "ron letter","letter" }));
        set_weight(200);
        if( clonep() )
        set_default_object(__FILE__);
        else
{       set("long","一封妙法仙尊寫給天山雪的信");
        set("unit","封");
        set("value",0);
 }
        setup();
}

