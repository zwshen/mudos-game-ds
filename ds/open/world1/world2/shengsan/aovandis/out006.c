// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}���諰���~");
	set("long", @LONG
�o�O�����Z�}���s���~�ɪ��D�����@�A�������Өӥh�h�۷��c���A
�F��N�O���Z�}�����諰���F�C�i�h(enter)���Z�}������аȥ����n��
�Z���Z�}�������`�ͬ��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out005",
	    "north" : __DIR__"out003",
	    "enter": __DIR__"room033",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

