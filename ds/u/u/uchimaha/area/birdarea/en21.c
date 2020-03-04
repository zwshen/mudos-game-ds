#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
你現在來到東北澤林的深處, 這附近沒有什麼東西, 
只有兩旁的樹叢, 和路上的幾根小草, 還有一個看起來
很舊的告示板(sign)前方便是人們常常迷路的沼澤地帶.
LONG
    );
 set("item_desc",([
     "sign":"你朝這告示板上看了看，發現上面寫著通過沼澤地帶的方法:\n
          "HIC"move ﹝方向﹞"NOR"\n
你不禁感謝立這個告示板的人，幫你解決了一個困擾。\n",
     ]));
 set("exits",(["west":__DIR__"en20",
               "east":__DIR__"en22",
             ]));
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
 replace_program(ROOM);
}           
