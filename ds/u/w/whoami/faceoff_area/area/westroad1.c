#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"西迴廊"NOR);

 set("long",@LONG
這裡跟東迴廊一樣, 兩側的浮雕也同等的美麗, 不過西迴廊
卻似乎比東迴廊短很多, 仿佛總共只有幾步之遙, 在你正感到奇
怪的時候, 忽然從你的下方傳來一陣聲音, 可是這裡並沒有出路
往下啊? 難道有什麼密道?.....
LONG);
 set("exits",([ "east":__DIR__"bird5",
                "west":__DIR__"westroad2",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

