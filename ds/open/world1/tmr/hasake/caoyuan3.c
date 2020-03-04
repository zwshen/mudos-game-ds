// Room: /open/world1/tmr/hasake/caoyuan3.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
你走進了這遍綿綿不絕的大草原，腳下是寸厚的青草，軟綿綿的還真
不好走，看來買匹馬來代步到是的好主意。西邊可以看見哈薩克帳篷，往
東去就是沙漠了。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"caoyuan2",
  "north" : __DIR__"caoyuan4",
  "south" : __DIR__"caoyuan7",
]));

	setup();
	replace_program(ROOM);
}
