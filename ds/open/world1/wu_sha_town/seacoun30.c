#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","無砂港");
set("long",@LONG
這裡就是無砂的港口了, 你看到你的北方與南方各有一棟
石屋, 原來北方就是無砂的鎮長, 林繁榮, 的住所, 而南方則
是無砂鎮船隻專用的修船廠.
LONG
    );
 set("exits",([ "west":__DIR__"seacoun29",
		"north":__DIR__"seacoun31",
		"south":__DIR__"seacoun33",
	    "east":__DIR__"seacoun37",
]));
 set("objects", ([__DIR__"../npc/thief" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            