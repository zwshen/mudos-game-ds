// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Ϥp��");
	set("long", @LONG
�o�̬O���Z�}�������Ϥp���A��ǬO�Ƥ����H�Ψ̵}�����;�άO�@
�Ǥp��Τp��C���W����H�ä��|�ܦh�A�ӨT���]�O�}�}�������C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out024",
	    "south": __DIR__"out032",
	    "north": __DIR__"out017",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}