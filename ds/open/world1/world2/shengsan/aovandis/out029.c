// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�̬O���Z�}�������ϡA�X�誺�p��b�o��ͪ��A�b�p�𪺮����٦�
�@�ǯ󥻬쪺�Ӫ��A�٦��@�Ǥp��]�b�o��ͪ��ۡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out028",
	    "south": __DIR__"out036",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}