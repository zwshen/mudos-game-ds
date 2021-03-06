#include <ansi2.h>

inherit NPC;

void create()
{
        set_name("仇池山", ({ "shan" }) );
        set("gender", "男性" );
        set("title", "形天");
        set("age", 54199);
        set("long","遠古時代所幸存的唯一形天族人，你可以向他學習(learn)戰舞(combat dance)。\n");
        set("level",1);
        set("attitude", "friendly");
        setup();
}

void init()
{       
    add_action("do_learn", "learn");
}

int do_learn(string str)
{
    if( !str || str != "combat dance")
        return notify_fail("你要向仇池山學習什麼？\n");

    if( this_player()->query("level") < 50 ) 
        return notify_fail("學習戰舞必須等級五十以上。\n");

    if( this_player()->query("war_art") < 999 )
        return notify_fail("你的戰鬥藝術不足 999 點，無法學習。\n");

    if( this_player()->query_skill("combat-dance") )
        return notify_fail("你已經學過戰舞了。\n");

    this_player()->add("war_art", -999);
    this_player()->set_skill("combat-dance", 20);

    message_vision(HIW"$N向$n請教有關「戰舞」的舞蹈動作。\n"NOR, this_player(), this_object());

    return 1;
}
