// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Ϥp��");
	set("long", @LONG
�p������ǦU���@���Ƥ����A�åB�شӤF�X�誺���;�ƦC�b�o��A
�p���O�H�e���ɹA�H�Ҩ����K�D�A���L�{�b�w�g�س]���f�o���F�A�H��K
�������Өө����C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out013",
	    "south": __DIR__"out017",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}