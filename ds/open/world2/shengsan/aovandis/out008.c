// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�D��");
	set("long", @LONG
�o�ӥѬf�o�Q�����D���C���T�~�N�n�׸��@���A�i���O�۷����
�C���Ǧ��Ǥp��p��b�ͪ��A�����B�ݡA�i�H�ݨ�X�������лE�����a��
�C�o�̬O���Z�}�������ϡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out007",
	    "south": __DIR__"out011",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}