// Room: /open/world1/tmr/advbonze/hill5.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上山小徑");
	set("long", @LONG
你正走在通往凌雲峰頂的小徑，由於道路狹窄，不時得讓路給過
往的人，以免相擠而撞到路旁的樹林。這條路往北的方向似乎只能大
走概到半山腰，再要通往凌雲峰頂，得再找其路徑了吧。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hill7",
  "southwest" : __DIR__"hill4",
]));

	setup();
	replace_program(ROOM);
}
