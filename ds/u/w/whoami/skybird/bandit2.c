#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","寨牆");
 set("long",@LONG 
這些是寨中的山賊們, 為了抵抗偶爾從山下來鏟除山賊的官
兵隊而築的牆, 牆非常的堅固, 而且牆上有許多的箭孔讓裡面可
以向外射箭, 看來很難攻進去….
LONG);
 set("exits",([ 
                "northwest":__DIR__"bandit1",
    ]));
 set("objects", ([__DIR__"npc/archer" : 1+random(4),
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();

}

