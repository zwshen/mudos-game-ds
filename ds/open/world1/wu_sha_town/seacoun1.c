#include <ansi.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short","森林小道");
set("long",@LONG
從這裡往再東走就會到無砂鎮了, 再從那往東走就是一片
汪洋大海, 而往西則會回到步靈城的護城河了, 你左右都是一
片綠油油的森林, 煞是美觀!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun2",
	"west":COMINGING_PAST+"area/river2",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
