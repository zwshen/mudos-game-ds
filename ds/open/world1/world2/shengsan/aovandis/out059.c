// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "����s�S");
	set("long", @LONG
�o�̪��a�դ񥭦a�ӱo���A����ݥh�O�@���M������y�A�X�����Y��
�G�b�a�W�A�٦��@�Ǥp��p��]�b�o��ͪ��C�ѪŤ����X���ն��b�䶡��
���ܪ��ǫȡA�X�������]�b�䶡�ּ֪������C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out060",
	    "north": __DIR__"out055",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}