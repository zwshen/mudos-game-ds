// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
���\�h�j�j�p�p���P���������ͪ��b�o��A���@�ǭ��������_�N�v
�b�j�𪺾�K���W�A���F���@���i�J��L�̪��K�D�A���ӬO�e�H�үd�U��
�A�o�̬O���Z�}�������ϡA�b���񦳤@���q�����Z�}�����D���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out037",
	    "north": __DIR__"out029",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}