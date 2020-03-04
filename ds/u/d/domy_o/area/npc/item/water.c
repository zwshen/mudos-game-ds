inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("都诀", ({ "tea pot","pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "都诀耚娩倒筁┕都ノ\n");
                set("unit", "");
                set("value", 20);
                set("heal_ap",45+random(6));
                set("heal_mp",45+random(6));
                set("heal_hp",45+random(6));
                set("water_remaining",50);
        }
}
void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
        if(me->query("level")>5)
        {
return notify_fail("猔種都诀禟眎: セノ矗ㄑ单き產都ノ\n");
        }
        else return ::do_drink(arg);
}
