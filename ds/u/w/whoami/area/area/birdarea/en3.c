#include <ansi.h>
#include <room.h> 

inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");

 set("long",@LONG
你現在來到一處樹木林立的地方, 一陣陣的風撲面而來, 樹
上有一堆的蟬正在那嘰嘰的叫著, 好似歡迎你來到這裡, 此路往
東方和北方分開, 你聽到不遠處有人砍樹的聲音。
LONG
 );
 
 set("exits",(["north":__DIR__"en5",
               "east":__DIR__"en4",
               "southwest":__DIR__"en2",
     ]));
        set("objects",([__DIR__"npc/chan" : 1+random(5),
               ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
 setup();
}

