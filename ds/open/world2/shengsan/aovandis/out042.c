// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
�K�����j�����ͪ��b�o�̡A�����u��q�𸭻P�𸭤�����L�A�@��
�@���ӲӪ��������u�g��a�W�n�����R���C�a�W���\���]�ܦh�A���ӧA�|
ť����Ωΰʪ��g�L�\���F�F���n���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out043",
	    "west" : __DIR__"out041",
	    "north": __DIR__"out038",
            ]));

	set("outdoors","forest");	// ��L
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}