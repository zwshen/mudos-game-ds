// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Ϥp��");
	set("long", @LONG
�o�̪��a�ե��Z�A���X����;�شӦb�p������ǡA�ѪŤ������`�`
���d�ܸU�ƪ��y���C�o�̬O���Z�}�������ϡA�A��B�����N�i�H���q��
���Z�}�����D���F�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out025",
	    "north": __DIR__"out014",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}