// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
�ѩ��쪺�c�Z�A�o�̨èS����L�~�����˪����G�A���ɭԥi�R���Q
���|�b�A���e���L�C�\�����𸭱����ܦa�W�����o����L�̦n���i���A��
�j����ڦb�a�W������¶�b�@�_�C�o�̬O���Z�}�������ϡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out044",
	    "west" : __DIR__"out042",
	    "south": __DIR__"out051",
            ]));

	set("outdoors","forest");	// ��L
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}