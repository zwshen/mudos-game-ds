#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name(HIW"醫療術士"NOR,({"doctor"}) );
       set("nick",HIW"心靈術士"NOR);
        set("long","一名擁有神奇力量的醫療人員，兼售些好東東！\n");
        set("sell_list",([
__DIR__"obj/light-gun.c"     :10,
__DIR__"obj/light-clip.c"    : 10,
__DIR__"obj/pill.c"   :10,
__DIR__"obj/pill1.c"    :10,
        ]) );
set("age", 30);
set("level", 10);
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
