// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�Ѱg�a");
	set("long", @LONG
�o�̬O���Z�}�������ϡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out058",
	    "north": __DIR__"out053",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}