// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�q���ǨӤ@�}�}�I�S�ӹL�����T���n���A�ݨө��訫�N�O�q�����Z
�}�����D���C�o�̬O���Z�}�������ϡA�S������S�O���a��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out034",
	    "south": __DIR__"out040",
	    "north": __DIR__"out027",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}