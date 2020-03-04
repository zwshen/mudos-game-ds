#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石道");
set("long",@LONG
你終於從森林中走出來了, 眼前是一條通商用的青石道, 你
發現你的四周有許多商人, 但是他們的貨物都是打算運出海外銷
的, 因此不會在此賣人, 從這裡再往東就會到無砂鎮, 往西則會
回到步靈城.
LONG
    );
 set("exits",([ "west":__DIR__"seacoun1",
		"east":__DIR__"seacoun3",
]));
 set("objects", ([__DIR__"npc/salesman" : 3,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
