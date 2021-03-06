inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("水井",({"well"}));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這是一個供人飲水用的水井，水井的深度好像很深的樣子。\n");
                set("unit","座");
                set("no_get",1);
                set("no_sac",1);
                set("value",1);
                set("heal_mp",random(10));
                set("heal_ap",1+random(10));
                set("water_remaining",250);
        }
        set("drink_msg","$N從水井裡弄了幾口水喝。\n");
    set("finish_drink_msg","$N把水井裡餘下的水喝光了。\n");
        setup();
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
                return notify_fail("你注意到水缸上貼了張佈告: 本用水只提供等級五級以下的玩家飲用。\n");
        else return ::do_drink(arg);
}

