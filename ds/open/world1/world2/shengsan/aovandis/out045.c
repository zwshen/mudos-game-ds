// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
��L���K�צb�o�̦��ܤj���t�O�A����O�����}���A�ӪF��o�O����
�K���C�o�̦��@�ǴӪ��ͪ��b��U�Ať�����Ǻ������Ӫ��٥i�H���Ӱ���
�C��F�W���еۤ@�h�C�a�A�٦��ǲӤp�����y�q���_���������y�X�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out046",
	    "west" : __DIR__"out044",
	    "north": __DIR__"out039",
            ]));

	set("outdoors","forest");	// ��L
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}