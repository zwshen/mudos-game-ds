// Room: /open/world1/tmr/advbonze/hill10.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�ѱ�");
	set("long", @LONG
�A�����b�ⶳ�p�W�ӡu�W�ѱ�v�W�A�A�i�H�ݨ쩵�۩��_�ӳq��
�s�����@�`�@�`�ѵM�۱�A�A��_�F�Y���s����F�L�h�A���G��
���@�q���������o���C
LONG
	);
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill11",
  "southdown" : __DIR__"hill9",
]));

	setup();
	replace_program(ROOM);
}