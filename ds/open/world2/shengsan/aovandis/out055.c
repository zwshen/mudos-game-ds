// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�����L");
	set("long", @LONG
�o�̦��Q�X�ʰ��j������ߦb�o��A�٦��\�h�������b�K�Y�W�s�s
�óڡA����ݥh�i�H�ݨ�@�y�Ѻ񪺴�y�A�򭱤Ϯg�Ӷ������������I�I
���{�G�ï]�A�n�����R�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out059",
	    "north": __DIR__"out050",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}