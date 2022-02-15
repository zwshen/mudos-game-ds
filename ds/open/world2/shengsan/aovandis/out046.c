// ���Z�}������
// LV 1~50
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "��L");
	set("long", @LONG
���j����L�N�o�����o�S������Ŷ��i�H���A�ۥѲ��ʡA�A�ȯ�q��
��P��줧�����_���p�i�h�C�H�̤w�g���ܪ����ɶ��b�o�̨��ʹL�F�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out045",
	    "east" : LUKY_NOW"area_1/room61",
            ]));
	set("item_desc",([	
	"�_��" : "�A�o�{�o�ӻ��_���G�i�H�p(drill)�i�h�C\n",
	])	);
	set("outdoors","forest");	// ��L
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
	if(arg!="���_") return notify_fail("�A�n�p����̣�?\n");
	if(me->is_busy()) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
	message_vision("$N�p���l�l���p�i�L�������_���C\n",me);
	me->move(__DIR__"out053");
	message_vision("$N�q��L�Ǫ��p�}�p�F�X�ӡC\n",me);
	return 1;
}