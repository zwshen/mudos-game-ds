// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "���Z�}������");
	set("long", @LONG
�o�̬O���Z�}�������ϡA�����Z�}���ܪ�C���n���N�i�H�ݨ�q����
�Z�}�����䰼�����D���C�ӧA�i�H�D����ǨӪ��}�}�j���۴���������
�̾����C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out003",
	    "south": __DIR__"out005",
	    "north": __DIR__"out001",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}