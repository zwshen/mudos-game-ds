// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�ӷ~�D��");
	set("long", @LONG
�o�̪����q�۷������A�}�����r�p�H�`�|����ı���[�֦樮�t�סA
����٦��樮�@��A�o���D���O�q�����Z�}�����������D���A�ҥH������
�ƥؤ]�۷��h�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out034",
	    "north": __DIR__"out018",
            ]));
	set("light",1);
	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}