// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�������O�͡A�èS��������}�o�A���ӧA�]�|�ݨ�X�����ߦb�o��
���A�A�o���٦��@�Ǽo�󪺽��L�C�A�o�{�o�̨ä��A�X�樫�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out011",
	    "east" : __DIR__"out063",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}