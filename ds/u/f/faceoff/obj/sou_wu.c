inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("首烏", ({ "sou wu", "wu" }));
        set("long",@LONG
這是一種常見的中藥藥材, 藥性屬陰, 通常被用來調養內息, 
也可生食, 是不錯的補品!
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("material","plant");
                set("value", 27);
                set("attr/wound",2);  
                set("heal_ap",15);
                set("heal_hp",5);
                set("attr_one","plant"); 
                set("attr_two","yin");  
                set("food_remaining", 1);  
                set("eat_msg","$N吞下一個首烏\n");
                set("eff_msg","你頓覺丹田活潑潑的, 一股內息油然而生 ! \n");
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
        if(me->query("mp")<30)
        {
                return notify_fail("你的精神力(MP)已經不夠了, 再吃就破表囉。\n");
        }
        else
        {
                set("heal_ap",33);
                me->receive_damage("mp",31);         
                return ::do_eat(arg);
        }
}
