// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
�@�ʤ@�ʪ��j��N�b�A�����e�A�ƶq���|�ܦh�A�j�h�ƬO�w�������
�A�]���X��p��b�j�𪺤U���A�Ů��ܱo�s�A�F���֡C�A�i�H�ܲM������
�즳�H���L������A�i��O��b�o���񪺩~���үd�U���a�H
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out038",
	    "north": __DIR__"out021",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}