// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
����b�o��ͪ��A�o�̨èS������u�~���ìV�A�A���n�价�ݥi�H��
��@�j������L�q�ߦb�n��A�ѪŪ����ण�ɪ�����s�C���_�i�H��
�q�����Z�}���F�������D���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out021",
	    "north": __DIR__"out015",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}