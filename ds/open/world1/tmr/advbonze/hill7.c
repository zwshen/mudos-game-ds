// Room: /open/world1/tmr/advbonze/hill7.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上山小徑");
	set("long", @LONG
你正走在通往凌雲峰頂的小徑，小路兩旁樹林的樹枝，不時的摩
擦到你的衣服，和路過的行人，也常得相互讓路，才能勉強通過。這
條路往南的方向過去可下凌雲峰，往北的方向則是更深入林處。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hill5",
  "north" : __DIR__"hill8",
  "east" : "/open/world1/tmr/frost/footway",
]));
	set("no_clean_up", 0);
	set("outdoor", "forest");
	set("current_light", 5);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
