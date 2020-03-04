#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
這裡就是天梟冶藥一派的大廳了, 你發現這裡是循這一根
大大的柱子建築, 你不禁想要調查調查柱子的存在所為為何? 
同時你也發現一些遊人也在看著柱子.
LONG
    );
 set("exits",([ "north":__DIR__"pill5",
		"south":__DIR__"pill6",
       "west":__DIR__"pill3",
    ]));
 set("item_desc",([
        "柱子":"一根大大的柱子, 從這個角度看不出有什麼異常.\n"
    ]));
 set("objects", ([__DIR__"npc/traveller" : 2,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
