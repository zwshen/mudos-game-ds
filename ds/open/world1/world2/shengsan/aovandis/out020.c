// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}���������~");
	set("long", @LONG
�o�O�����Z�}���s���~�ɪ��D�����@�A�������Өӥh�h�۷��c���A
�_��N�O���Z�}�����������F�C�i�h(enter)���Z�}������аȥ����n��
�Z���Z�}�������`�ͬ��C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out019",
	    "south": __DIR__"out028",
	    "enter": __DIR__"room009",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
