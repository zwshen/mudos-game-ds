// Room: /u/l/lestia/area/map_6_2.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�[�Ш��D");
	set("long", @LONG

�@�����̤�ҫسy�����D�b�A�}�U�Q�A�򪺩N�N�@�T�A�ϩ��b��ĳ�ۧA
�e�i���}�B�ӨI���A�n��b�[�Х𮧪��Q���̡A���q���F�۱Ъ��j�����U
�A�e��h�O���D�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_6_3",
  "north" : __DIR__"map_5_2",
  "south" : __DIR__"map_7_2",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}