// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Ϥp��");
	set("long", @LONG
�o�̬O���Z�}�������Ϥp���A�o�O�H�e���ɹA�H�Ҩ����K�D�A���L�{
�b�w�g�س]���f�o���F�A�H��K�������Өө����C���X����;�شӦb�p
������ǡA�ѪŤ������`�`���d�ܸU�ƪ��y���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out033",
	    "west" : __DIR__"out031",
	    "north": __DIR__"out025",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}