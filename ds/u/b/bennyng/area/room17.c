// Room: /u/b/bennyng/area/room17.c

inherit ROOM;

void create()
{
	set("short", "�B�����|");
	set("long", @LONG
�����_�~�y�t���h���v�T�A�o�̪���ū�@�U���D��������Q����
�]��A�p�G�A����h�@����A���ȷ|�۲D�r�I�I
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"room16",
  "westdown" : __DIR__"room18",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}