// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}���F�����~");
	set("long", @LONG
�o�O�����Z�}���s���~�ɪ��D�����@�A�������Өӥh�h�۷��c���A
����N�O���Z�}�����F�����F�C�i�h(enter)���Z�}������аȥ����n��
�Z���Z�}�������`�ͬ��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out008",
	    "enter": __DIR__"room016",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
