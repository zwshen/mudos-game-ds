// Room: /u/d/donhow/area/a2.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a7",
  "west" : __DIR__"a1",
  "east" : __DIR__"a3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}