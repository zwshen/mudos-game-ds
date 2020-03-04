#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("商人" , ({ "seller" }) );
        set("level",10);
        set("race","人類");
        set("age", 30);
        set("long","你眼前的這位，正在這間廉價商店的老闆，你可以跟他看看有什麼衣服買。\n");
        set("sell_list",([
__DIR__"eq/ecloth.c" : 1,
        ]) );
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_list","list");
}
