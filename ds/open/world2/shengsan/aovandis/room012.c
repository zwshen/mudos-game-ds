// ���Z�}��
// LV 1~50
#include <room.h>  //�n�[���n�o�@��
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", HIC"�}���j�D"NOR);
	set("long", @LONG
�A�b���Z�}�����}���j�D�W�A�o���j�D�O��󫰸̪��F�b��A���F��
���N�O�F�����F�A�b�n�䦳�@���]�_���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room013",
	    "west" : __DIR__"room011",
	    "south": __DIR__"room078",
	    "north": __DIR__"room087",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
 	create_door("north","�K��","south",DOOR_LOCKED,"ironkey");
	setup();
}
