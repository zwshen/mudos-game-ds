// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Ϥp��");
	set("long", @LONG
���Ϫ��p���`�O���|��j���ӱo�e���A��Ǧ��Ƥ����H�Τ@�ǴӪ��A
�C�o�O�H�e���ɹA�H�Ҩ����K�D�A���L�{�b�w�g�س]���f�o���F�A�ϱo�n
�q�o��g�L�����l����n�r�p�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out034",
	    "west" : __DIR__"out032",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}