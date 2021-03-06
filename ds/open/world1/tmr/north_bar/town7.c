// Room: /open/world1/tmr/north_bar/town7.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－大井處");
	set("long", @LONG
眼前這口數十年的大井是這些村民生活的最主要水供給來源
，在幾十年前就被這裡當地的居民挖掘出來，往裡面一看，竟是
清澈乾淨的井水，喝起來應該相當順口。往北的方向是一座石壁
，石壁下竟有條直直的石路，往北不知會通到什麼地方。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town6",
  "north" : __DIR__"town8",
  "east" : __DIR__"town15",
  "west" : __DIR__"town14",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
    set("objects", ([
        "/open/world1/obj/well" : 1,
        __DIR__"npc/traveller" : 1,
    ]) );


	setup();
	replace_program(ROOM);
}
