// Room: /open/world1/tmr/hasake/senlin2.c

inherit ROOM;

void create()
{
	set("short", "針葉林");
	set("long", @LONG
這是極西天山腳下的一片針葉林，林中鳥獸成群，滿地鋪蓋著厚厚一
層鬆針。北方的一座高聳的山脈便是天山了，山上終年積雪，山下卻是綠
樹成蔭。往南走便是大草原，有辛勤的哈薩克族人在那裡放牧。你走著走
著，竟然迷失了道路。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"senlin3",
  "north" : __DIR__"senlin11",
  "south" : __DIR__"senlin12",
  "east" : __DIR__"senlin1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wolf1" : 2,
]));

	setup();
	replace_program(ROOM);
}
