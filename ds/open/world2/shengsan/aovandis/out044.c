// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
��L���R���ۿ@������h��A�M�s���Ů����A�ɵM�۱o�C�b���P��
�줧���]�|���U�د����Ӫ��ͪ��A�����٥i�H��@�ħ��C�a�W���G���X��
�p���X�S�b�o�̪��}�L�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out045",
	    "west" : __DIR__"out043",
            ]));

	set("outdoors","forest");	// ��L
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
