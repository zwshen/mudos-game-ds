inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("浮蓮", ({ "fu lotus", "lotus" }));
        set("long",@LONG
這是一種水生的中藥藥材, 藥性屬陽, 與地錢一樣, 有些許的毒
素, 但經煉製後便無毒, 通常用於創傷, 有不錯的療效.
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("material","plant");
                set("value", 15);
                set("attr/wound",1);  
                set("heal_hp",20);
                set("heal_ap",5);
                set("heal_mp",5);
                set("attr_one","plant"); 
                set("attr_two","yang");  
        }
        setup();
}
