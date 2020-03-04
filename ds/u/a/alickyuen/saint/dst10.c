#include <ansi.h>
//updated 26/12
inherit ROOM;
void create()
{
	set("short", HIC"ST。Road＠Gate"NOR);
	set("long", "來到這樣後，你感到人群這樣比南方增加了不少，但你聽到那邊聲音
很大，很像有一些事情在那邊發生了似的。你好奇心卻駒使你去那邊湊湊
熱鬧，加快腳步看看吧。\n");
 set("exits",([ 
"north":__DIR__"dst18.c",
"south":__DIR__"dst9.c",
]));
   set("outdoors","land");
	setup();
	replace_program(ROOM);
}
