// Room: /open/world1/tmr/goat_maze/maze5.c

inherit ROOM;

void create()
{
	set("short", "�Ϩk���g�c - �����");
	set("long", @LONG
�A�����b�@�ӥH���Y��򦨪��g�c�A���G�O�X�d�~�e�N�ئb�o�˪L��
���C��⪺�C�a�Ϊ�󪦺��F�|�g�@���S�@��������A�P�˪L�۵M�ӵM�a
�ĦX�b�@�_�C�A���M���B�b�g�c�����A���O�ˤ]����۷Q�n���}�C
LONG
	);
	set("shrot", "�Ϩk���g�c - �����");
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/bariour2" : 2,
  __DIR__"npc/bariour1" : 2,
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"maze3",
  "northwest" : __DIR__"maze7",
  "north" : __DIR__"maze10",
  "northeast" : __DIR__"maze6",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}