// This is a room made by roommaker.
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST．SOFT"NOR);
	set("long", "這是Saint內唯一一間大酒店，因此常有很多人在流連，在假日更加
是人來人往。這裡看起來好像很豪華的樣子，在這大堂有一個自動售賣機
，你有需要的話可去看看。在大堂下面應該是房間之類的地方。\n");
set("valid_startroom", 1);
set("exits",([ 
"south":__DIR__"dst11",
"down":__DIR__"inn2",
]));
set("objects",([ 
__DIR__"obj/seller1" : 1,
]));
set("no_fight", 1); 
set("light",1);
	setup();
	replace_program(ROOM);
}
