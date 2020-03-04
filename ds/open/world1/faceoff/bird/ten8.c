#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","練武場");
 set("long",@LONG
你發現前面每一個門都上了重重深鎖, 看來不可能再往內
闖了, 你看到你的眼前有一個彪形大漢在鍛鍊身體, 不用說, 
他就是寨主了....
LONG
    );
 set("exits",([ "south":__DIR__"ten7",
    ]));
 set("objects", ([__DIR__"npc/bleader" : 1,
		  __DIR__"npc/ileader" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
