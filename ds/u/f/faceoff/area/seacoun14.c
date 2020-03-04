#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","現-狥め現场");
set("long",@LONG
硂柑琌現狥め現场, 稱讽礛碞ㄆ矪瞶玌, 簿﹡ぇㄆ
舘! ぃ筁タΑ狥め現场临璶┕ㄇ, 硂柑琌单快瞶ㄆ叭
单.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun15",
		"west":__DIR__"seacoun9",
]));
 set("objects", ([__DIR__"npc/wait_man" : 3,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
