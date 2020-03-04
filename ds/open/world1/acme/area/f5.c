// Room: /open/world1/acme/area/f5.c

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
這山洞十分狹小，必需矮身才能進來，在山洞深處，竟有許多乾
枯的骸骨，仔細一看卻是動物的屍骸，洞外的血跡延伸至此。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"f4",
]));
set("objects", ([ 
  __DIR__"npc/tan" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
