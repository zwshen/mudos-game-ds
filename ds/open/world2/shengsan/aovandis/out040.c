// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�̪��L���۷��M�n�A���\�h���p�H�ۤΤ@�ǰ��w��b�a�W�A�X��
���p��ͪ��b�o��A�ѤW���ն����G���b��A�ۤ�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out047",
	    "north": __DIR__"out035",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}