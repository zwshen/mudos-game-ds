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
	    "west" : __DIR__"out053",
	    "south": __DIR__"out058",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}