#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路");
set("long",@LONG
從這裡可以很明顯的聽到南方傳來一股喧鬧之聲, 原來鎮長
林繁榮別具巧思, 北市區固然繁榮, 自從南市區改為市集後與北
市區同等繁容!
LONG
    );
 set("exits",([ "north":__DIR__"seacoun20",
		"south":__DIR__"seacoun22",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            