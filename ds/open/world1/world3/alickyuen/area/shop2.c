// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST．WpShop＠Automatic"NOR);
	set("long", "這是Saint一間武器售賣店，因為有先進科技的關係，在這買賣已經不
用人手而改為以機器來完成。你可以打(list)來看看想賣的武器或道具。\n");
	set("exits", ([ /* sizeof() == 1 */
 "north":__DIR__"dst16",
]));
            set("objects", ([ /* sizeof() == 4 */
__DIR__"obj/seller2.c" : 1,
]));
set("light",1);
	setup();
	replace_program(ROOM);
}
