#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"茅屋"NOR);

 set("long",@LONG 
你一踏進這一間茅屋, 立刻感到一股檀香味, 你環顧了四週
, 卻只見到一把除魔劍和一具古箏, 顯然屋主是一個品德高尚的
高人居士......慢著! 你忽然想到, 除魔劍一向受武林排斥嗎? 
那麼為什麼牆上會掛著一隻除魔劍呢? ....難道此劍另有其它的
奧妙?....
LONG
    );
 set("exits",([ "west":__DIR__"eastroad3",

    ]));
 set("item_desc",([
        "除魔劍":"你仔細的觀察這一把劍, 發現此劍似匕而非匕, 似劍而非劍 , 且
是由極好的煉鋼打造而成, 使你實在想要摸一摸它.\n"
    ]));
set("objects", ([__DIR__"npc/san_kung" : 1,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

