// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
�U����L���`�B���h�A��L���K�״N�U���A���ɶ��A�|ť��@�ǩ_��
���n���A���O�ѬY�ذʪ��ҵo�X���Ať�o�A�߸̲��ͤ�򪺷Pı�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out037",
	    "south": __DIR__"out042",
	    "north": __DIR__"out030",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}