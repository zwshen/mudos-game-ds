// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�̨�B���O���Q�b�a�W���ۤl�A�H�μo��b�@�Ǫ����L�A�u���X��
���w��ͪ��b�ۤl�襤�A���L�o�̨ä��|�Ӵe���A���ɶ��]�|���C�C���L
���j�L�A�����ǡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out024",
	    "north": __DIR__"out013",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}