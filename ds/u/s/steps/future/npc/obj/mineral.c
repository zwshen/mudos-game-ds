inherit ITEM;
void create()
{
        set_name("礦石",({ "mineral" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一種礦石，看起來還蠻值錢的。\n");
                set("unit","堆");
                set("value",100);
        }
        setup();
}