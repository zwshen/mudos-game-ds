// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�ӷ~�D��");
	set("long", @LONG
�e�����ӷ~�D���̡A�T���B�����B�j�f���άO�ȹB���ܸ��_�A�]��
�o�̬O�Ӥj���s�A�ҥH���ɭԷ|�b�s�D���ݨ�o�Ӹ��q�X���ת����ɡA�A
���o���p�ߡA�K�o�y���@���l����ѡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out019",
	    "south": __DIR__"out026",
            ]));

	set("light",1);
	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}