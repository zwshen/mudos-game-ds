#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","主海政部");
set("long",@LONG
你步行許久, 終於到了這位海政司長官身邊了, 你發現他的
八仙桌上的公文數量居然高到看不見海政司長官的顏容! 只勉強
可以看見有一個人在公文中奮鬥, 幸好在他的東邊與西邊又各有
一位副師幫助, 否則真是不堪設想....
LONG
    );
 set("exits",([ "east":__DIR__"seacoun12",
		"west":__DIR__"seacoun13",
		"south":__DIR__"seacoun10",
]));
  set("item_desc",([
        "公文" : "一堆公文.....\n",
    ]));
 set("objects", ([__DIR__"npc/sea_master" : 1,
		  __DIR__"npc/bladeguard" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
}
             
