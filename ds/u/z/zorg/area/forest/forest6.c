// Room: /u/z/zorg/area/forest/forest6.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"forest5",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}