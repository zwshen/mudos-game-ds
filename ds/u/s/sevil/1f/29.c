// Room: /u/s/sevil/1f/29.c

inherit ROOM;

void create()
{
	set("short", "�k�Z");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"28.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}