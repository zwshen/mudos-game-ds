#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"晦林"NOR);

 set("long",@LONG
這裡是晦林的東南邊, 你發現這裡的溼氣又更高了一些, 所
以你也更不舒服了, 你忽然發現你腳下有許多小爬蟲類在爬來爬
去....
LONG
    );
 set("exits",([ "north":__DIR__"med21",
		"east":__DIR__"med19",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}