inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("七寒", ({ "seven cold", "cold" }));
        set("long",@LONG
這是一種中藥的藥材, 由於藥性極寒, 通常都是用在引出服用者
潛伏的靈力, 且不宜生吃.
LONG
);
        set_weight(55);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("material","plant");
                set("value", 25);
                set("attr/wound",1);  
                set("heal_hp",10);
		set("heal_mp",20);
                set("attr_one","plant"); 
                set("attr_two","yin");  
        }
        setup();
}