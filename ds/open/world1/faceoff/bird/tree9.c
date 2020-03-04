#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"參天古木"NOR);

 set("long",@LONG
你費盡千辛萬苦, 終於踏在這顆傳說中的神木前面, 你心中
的感動使你幾乎要流下淚來, 你舉首望了望眼前的神木, 只見樹
根錯綜複雜, 枝葉蒼蒼, 隱隱似乎透著靈氣, 果然好一棵神木!就
在你心中正感動於這棵神木之時, 你忽然舉頭發現樹枝上似乎..
....
LONG
    );
set("exits",([ "southwest":__DIR__"tree5",
    ]));
 set("item_desc",([
        "樹枝":"你舉頭凝望頭上的樹枝, 發現在根部有一圈痕跡, 
似乎有人上下這根樹枝, 你自信以你的輕功\基礎, 要跳上樹枝並不困難.\n"

    ]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_jump","jump");
}





int do_jump(string arg)
{        object me;
        me=this_player();
       if (arg != "樹枝") return 0;

        message_vision("只見$N身子一躍, 竟然跳上了樹枝! !\n"  ,me);
       me->move(__DIR__ "tree10");
return 1;
}






