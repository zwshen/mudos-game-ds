// Room: /open/world1/tmr/dragoncity/house2.c

inherit ROOM;

void create()
{
	set("short", "少帥府－大院");
	set("long", @LONG
這裡是少帥府的大院，當面一堵寬闊的白玉照壁，上書「
忠心報國」四個大字，地下是一色的青磚鋪地，四周種了幾棵
大樹，有幾個僕役正在院中灑掃，北面是少帥府的客廳。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"house1",
  "north" : __DIR__"house3",
]));
	set("current_light", 2);

        set("objects", ([
                __DIR__"npc/du-qing" : 1,
        ]) );
	setup();
	replace_program(ROOM);
}
