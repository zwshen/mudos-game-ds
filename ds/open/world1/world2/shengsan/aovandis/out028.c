// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
���\�h���p����b�o��ͪ����@���A�\�h�������M�e���X�{�b�o�䭸
�R�V���A�X���j���Y�Q��b�o���p���ᤧ���C�Ať��_��ǨӶ}�����n��
�A�n���_��O�@���D���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out029",
	    "west" : __DIR__"out027",
	    "north": __DIR__"out020",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}