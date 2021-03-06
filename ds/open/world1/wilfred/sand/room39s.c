// Room: /open/world1/wilfred/sand/room39s.c

inherit ROOM;

void create()
{
	set("short", "黃沙嶺");
	set("long", @LONG
經年累月的風沙，堆出了這塊黃沙丘陵地，丘陵上寸草不生，鳥
獸難見，當地人稱之為『黃沙嶺』，此丘陵為連接舊磐龍城與黃沙道
之要道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room39",
]));
	set("outdoors", "land");
	set("current_light", 1);
	set("no_clean_up", 0);
    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/npc10" : 1,
    ]));

	setup();
	replace_program(ROOM);
}
