// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���ϹA��");
	set("long", @LONG
���@�ƨ����L�]�b�o��A�b�����L���ﭱ�A�i�H�ݨ�@���@�����A��
�b�j�a���W�A�M���L�L���j�۽_�l�A�N�ϩ��O���W�����@��W�U�\�ʵۡA
�o�̬O���Z�}�������ϡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out025",
	    "west" : __DIR__"out023",
	    "south": __DIR__"out031",
	    "north": __DIR__"out016",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}