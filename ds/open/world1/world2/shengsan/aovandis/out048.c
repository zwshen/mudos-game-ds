// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�a�W���������A���H�ȤW���ʤH�t���߯ߡA���䪺�����g���F�ƹ�
�k�k�k�k�C�A�٥i�H�ݨ�@�Ǥp�Ħb����^�����A�A�@�Ƥѯu�L������
�ˡA���A�Q�_�p�ɭԪ��I�I�w�w�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out049",
	    "west" : __DIR__"out047",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}