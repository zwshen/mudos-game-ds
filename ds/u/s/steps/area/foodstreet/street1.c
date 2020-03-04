#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"ST．Street＠FoodStreet"NOR);
        set("long",
        "一走進來這裡，你就看到各式各樣的世界英食盡在眼簾，而且當中的\n"
        "香味就更加難以形容。這裡的坐位都已經差不多坐滿了人，你就可以試試\n"
        "再找找位子坐下來，嘗嘗這裡食物的味道。\n"
);
        set("exits", ([ /* sizeof() == 4 */
          "north":"/u/s/steps/area/street2.c",
          "east":"/u/s/steps/area/counter1.c",
          "west":"/u/s/steps/area/counter2.c",
          "south":"/u/s/steps/area/door.c",
        ]));
        setup();
}
