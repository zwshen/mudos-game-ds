// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
�o�̪����ä��|�ܦh�A�ҥH�i�H�ݨ�j�������ѪšC�ѪŤW���ɦ�
���N�b�W��L�ۡA���G�o�����y�������C���ɴX�����Q���|�b��L����
�����D�A���A�b�o�Ѧa�����C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out051",
	    "south": __DIR__"out056",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}