// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���ϹA��");
	set("long", @LONG
�o�̦��@��@��ЮG�ҳ�_�Ӫ��A�СA�̭��ت��O�����⪺�_�̡A��
�@�ӹA�ҥ��b�ϥΦ��ξ����ν_�l�A�A���y�W�@�y�r�֪����e�A�Q���o��
�����άO�Ӥj�צ��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out024",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}