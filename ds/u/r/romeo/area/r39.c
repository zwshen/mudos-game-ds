// Room: /u/k/king/area/r39.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�G�Q�~�e���ٯu���]���b�o�@�ԡA���ٯu�ϥΤ��P�ѡA�N�]������
�A�]�N�o�̵����F�A�쥻���R���s�e�{�b�ܦ��@�M���g�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"r38",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
