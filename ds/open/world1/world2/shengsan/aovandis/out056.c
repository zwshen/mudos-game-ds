// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
�o�̪��Y�צ��I�ɱסA�O�ѥ_���n�ɰ��C���L�o�̪���줴�M�ܦh�A
���������G���A���ʧ������G�p���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out062",
	    "north": __DIR__"out052",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}