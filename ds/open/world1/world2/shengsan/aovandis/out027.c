// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�̬O���Z�}�������ϡA�N�b�D��������A�p�G�n�h���Z�}���A����
���_���N�i�H�ݨ�q�����Z�}�������n�ӷ~�D���F�C�o�̥u���@�ǸG�p��
�Ӫ��A�Τ@�ǸH�ۦӤw�A�èS���������S�O���a��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out028",
	    "south": __DIR__"out035",
	    "north": __DIR__"out019",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}