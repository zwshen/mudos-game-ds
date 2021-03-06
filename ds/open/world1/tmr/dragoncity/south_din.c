// Room: /open/world1/tmr/dragoncity/south_din.c

inherit ROOM;

void create()
{
	set("short", "丁字街");
	set("long", @LONG
這裡是磐龍城南城的丁字街口。向南一直通向朱雀門，
東面和西面是一條筆直的青石大街，通向城內。北面是一堵
上蓋紅色琉璃瓦的高牆，裡面是少帥軍統帥寇仲的府邸。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"southroad2",
  "south" : __DIR__"southgate1",
  "north" : __DIR__"house1",
  "east" : __DIR__"southroad1",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
