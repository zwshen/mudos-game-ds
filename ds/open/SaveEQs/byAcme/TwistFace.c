#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIG"麻花臉譜"NOR ,({ "twist face", "face" }) );
        set("long",@long
這是一張 流影(Acme) 不小心遺落在人間的臉譜。
long
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit", "張");
                set("value", 0);
        set("no_drop",1);
        }
        setup();
}

int query_autoload() { return 1; }

void init()
{
    add_action("do_twist", "twist");
}

int do_twist(string str)
{
    if( !str || str != "face" ) 
        return notify_fail("你想把什麼變成麻花？\n");

    if( this_player()->query_condition("FaceIntCD") )
        return notify_fail("你現在還不想變成麻花臉。\n");

    message_vision(HIG"$N變成了個大麻花臉。\n"NOR, this_player());

    this_player()->set_temp("FaceInt", 3);
    this_player()->add_temp("apply/int", 3);
    this_player()->apply_condition("FaceInt", 80);
    this_player()->apply_condition("FaceIntCD", 300);

    return 1;
}
