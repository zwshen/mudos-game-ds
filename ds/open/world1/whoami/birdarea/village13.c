#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"北市街"NOR);
 set("long",@LONG
你繼續往北走, 這裡的攤位沒有前面的多, 感覺有點冷清, 
在你的東方是獵狐村村長的家, 你可以到他那兒, 跟他談天. 在
你的西方是獵狐村英雄的家, 你可以去那看看他為什麼被稱為英
雄.
LONG
    );
 
 set("exits",(["north":__DIR__"village15",
               "south":__DIR__"village12",
               "east":__DIR__"village14", 
               "west":__DIR__"village19", 
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}

