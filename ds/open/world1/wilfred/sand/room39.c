// Room: /open/world1/wilfred/sand/room39.c

inherit ROOM;

void create()
{
	set("short", "黃沙嶺");
	set("long", @LONG
經年累月的風沙，堆出了這塊黃沙丘陵地，丘陵上寸草不生，鳥
獸難見，當地人稱之為『黃沙嶺』，此丘陵為連接舊磐龍城與黃沙道
之要道，此處再往西走，便可到舊磐龍城之遺址，西北方遠處可隱約
看到一座城。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room39s",
  "east" : __DIR__"room38",
  "westdown" : __DIR__"room40",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
