// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������~");
	set("long", @LONG
�A�����b���q������~�A��ꪺ����w�g�b�o�O�ö��Z�}�����l����
�d�~�F�A���M���Ԥ�������A���O�o�����­��C�����B�ݥi�H�ݨ�X��
�֭n���\�����A���_�N�O�@�����Z�D���F�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out012",
	    "south": __DIR__"out015",
	    "north": __DIR__"out008",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}