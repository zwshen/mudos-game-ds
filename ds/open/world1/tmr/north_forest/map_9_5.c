// Room: /u/l/lestia/area/map_9_5.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-武道場");
	set("long", @LONG

這裡是長老為了讓靈幻教徒有個地方可以磨練自己的功力，而特別指示
負責建設的人員建立的武道場，方便教徒磨練測試功力。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_9_6",
  "north" : __DIR__"map_8_5",
  "west" : __DIR__"map_9_4",
]));
        set("objects", ([ 
__DIR__"npc/giautoo":3,
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
