// liangong.c 練功室
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "練功\室");
	set("long", @LONG
這座石室形狀甚是奇特，前窄後寬，成為梯形，東邊半圓，西邊卻
作三角形狀，原來這是以前重陽祖師的練功室，前窄練掌，后寬使拳，
東圓研劍，西角發鏢。
LONG	);
	set("exits", ([
		"northeast" : __DIR__"mudao03",
	]));
        set("objects", ([ /* sizeof() == 1*/
          __DIR__"npc/apprentice" : 3,

        ]));      

	setup();
	replace_program(ROOM);
}
