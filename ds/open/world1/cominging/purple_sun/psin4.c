inherit ROOM;

void create()
{
	set("short", "山腳下");
	set("long", @LONG
你現在在紫陽山的山腳下面，在這裡有些花草，好像有些可以食用
飽肚之草，不過你卻不怎麼認得，你現在還在環繞山的森林之中，不過
在你面前的卻是一座陡峭的山。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"psin3.c",
  "west" : __DIR__"psin5.c",
  "east" : __DIR__"psin2.c",
]));
	set("objects", ([
  __DIR__"npc/passenger.c" : 1
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("item_desc", ([
  "花草" : "一些野生的花草, 長在旁邊的朽木上. \n",
]));
	setup();
	replace_program(ROOM);
}