// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
�o�̦��@�ǰ��j�����b�o����G�A��W���Q�����ɪ��b�L�����D��
���A���⪺�����]�b�o��E���A�]���a�W�����F�A�v���R���ᦷ�C�A�i�H
�ݨ�F��V���H���L������C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out038",
	    "west" : __DIR__"out036",
	    "south": __DIR__"out041",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
