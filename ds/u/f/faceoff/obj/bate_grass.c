inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("百里", ({ "bate grass", "grass" }));
        set("long",@LONG
這是一種非常常見的中藥藥材, 藥性屬陽, 因過於強烈而不宜
生食, 通常用於內傷.
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("material","plant");
                set("value", 30);
                set("attr/wound",1);  
                set("heal_mp",10);
		set("heal_ap",20);
                set("attr_one","plant"); 
                set("attr_two","yang");  
        }
        setup();
}
