//updated
#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name(HIW"奸商"NOR, ({ "Bad seller","seller"}));
        set("long","你一望過去就見到他在奸笑,看起來不大友善.......\n");
        set("sell_list",([
__DIR__"obj/ticket" : 10,
        ]) );
set("age", 30);
set("level", 10);
        set("chat_chance", 6);
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
