// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�̥ͷN�s�M�A�L�L���M���q�n��j�ئӨӡA�C��Τp��b�o���B
�ͪ��ۡA���ɧA�|���}�ꪺ�ˤ��ӵo�X�ǹǪ��n���A�@����\�����Ӥ]
�|�b�A���䭸�L�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out022",
	    "south": __DIR__"out030",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}