
inherit  ITEM;
void  create()
{
       set_name("石墩",({  "stool"  }));
        set_weight(20000);
    set("long","這是張大理石製的凳子。\n");
        if(clonep()) set_default_object(__FILE__);
        else
        {
                set("unit",  "張");
                set("material","stone");
                set("value",  2000);
                set("no_get",  1);
                set("amount",30);
        }
        setup();
}
