// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
�\�h�����j�����b�A���|�P���۩��W�ͪ��A�A�ݨ�ӲӪ��������u
�q�c�Z���𸭶��g�U�ӡC�a�W���Q���j����ڥH������������A�ҽL�ڡA
�ϱo�A���S���ߨ����a�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out052",
	    "north": __DIR__"out043",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}