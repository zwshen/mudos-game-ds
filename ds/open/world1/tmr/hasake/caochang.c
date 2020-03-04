// caochang.c 草場
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "草場");
        set("long", @LONG
這一族哈薩克人大概已經習慣了定居生活，於是做了個大草場。春夏
把遠處肥嫩的水草割下來堆在這裡，以備秋冬季節畜生的食料。這裡堆滿
了一堆堆帳篷大小的草堆和幹草(gancao)，看起來不下千堆。
LONG);
        set("exits", ([
//            "northdown" : __DIR__"pmchang",
//            "westdown" : __DIR__"shuijing",            
            "southeast" : __DIR__"pmchang",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1
        ]));
        set("item_desc", ([
                "gancao" : 
            "這是堆積在草場理的草堆，地上還零零散散地放了好多已經曬幹的水草。你可以幫助牧民們把幹草堆成堆。\n",
        ])); 
        set("outdoors", "land");
        setup();
        replace_program(ROOM);

}
