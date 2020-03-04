// Room: /u/m/matlab/area/r1.c

inherit ROOM;

void create()
{
	set("short", "斷陽路");
	set("long", @LONG
這裏的光線更加昏暗了，搖曳的燭火就是隨時會熄一般，
角落裏有著淡淡的影子，不停地晃動著。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r2.c",
  "south" : __DIR__"start.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
