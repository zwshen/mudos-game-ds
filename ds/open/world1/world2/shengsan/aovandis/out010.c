// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�̦��@�Ǫ�����A�H�Τ@�Ǫ��H�۩M�\��A�٦��@�Ǽo�󪺽��L�A
�A�o�{�_�観�@�����Z���D���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out009",
	    "south": __DIR__"out013",
	    "north": __DIR__"out004",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}