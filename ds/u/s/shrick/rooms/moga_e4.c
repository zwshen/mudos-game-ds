// Moga_road_e4.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"莫格大道─ "HIW"東路"NOR);
        set("long",@LONG
  這條猶羅村東西向的道路莫格大道，此處是東路。
從這向南走是旅館。
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"door2",
                "west"    : __DIR__"moga_e3",
                "south"    : __DIR__"hotel",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
