// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�D��");
	set("long", @LONG
�o���D���O�Ѭf�o�Q�����A���F�q�����Z�}���C���Ǫ��_���u���@��
����A���ө����B�ݷ|�ݨ�@��ʪ��j��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out005",
	    "south": __DIR__"out010",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}