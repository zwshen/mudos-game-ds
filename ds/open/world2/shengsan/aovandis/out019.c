// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�ӷ~�D��");
	set("long", @LONG
�o�����Z�}����~���D���A�O���۷�e�����ӷ~�D���A���l�Өө���
���۷��W�c�A�D�����������O�Ʀ��@��ơA��F�ߤW�i�O�۷����G�O�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out020",
	    "west" : __DIR__"out018",
	    "south": __DIR__"out027",
            ]));

	set("light",1);
	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}