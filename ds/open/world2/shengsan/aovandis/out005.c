// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�D��");
	set("long", @LONG
�o�O�@������p�]�٤��W�j�������A���F�N�O�D�W�I�⪺���Z�}���F
�C�Өө����������g�`�z�L�o��������~�p���A��K����q�]�O���Z�}��
�c�a����]���@�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out006",
	    "west" : __DIR__"out004",
	    "north": __DIR__"out002",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}