// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�ӷ~�D��");
	set("long", @LONG
�o�O���۷�j�������A�u�ۥ_��樫�N�i�H��F���Z�}���F�C�ө���
�����b�A���ǩI�S�ӹL�A�ϱo�A��������x�����Pı�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out035",
	    "west" : __DIR__"out033",
	    "north": __DIR__"out026",
            ]));
	set("light",1);
	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}