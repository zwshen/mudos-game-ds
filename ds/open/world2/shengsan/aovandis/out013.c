// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�@������Τ@�ǸH�۬O�o�̦a�W���D�n�����A�@��������a�b�o��
�w�g�ܤ[�ܤ[�F�C���ӷ|���X�[������q�Ť������ݸ̭��L�A�άO��F��
�ߤQ���|���X�������b�Ť������C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out014",
	    "south": __DIR__"out016",
	    "north": __DIR__"out010",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}