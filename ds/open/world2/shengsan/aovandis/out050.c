// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�����L");
	set("long", @LONG
�Ů��M�D�n�F�_�ӡA�L�L���M���ﭱ�V�A�j�ӡA�A�ݨ��n�誺��
�B���@�y�Ѻ񪺴�y�C�d�g�P�����۬ۨp�V�b�@�_�A�����A�Ҩ����a���C
�o�̬O���Z�}�������ϡA�A�i�H��B�������q�����Z�}�����D���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out049",
	    "south": __DIR__"out055",
	    "north": __DIR__"out041",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}