// ���Z�}������
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "�Ѱg�a");
	set("long", @LONG
�o�̬O���Z�}�������ϡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out054",
	    "south": __DIR__"out057",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
}

void init()
{
	add_action("do_drill","drill");
	return;
}

int do_drill(string arg)
{
	object me;
	me = this_player();
	message_vision("$N�p���l�l���p�i�L�����p�}���C\n",me);
	me->move(__DIR__"out046");
	message_vision("$N�q��L�Ǫ����_���p�F�X�ӡC\n",me);
	return 1;
}