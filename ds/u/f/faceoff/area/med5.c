#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"蓮池"NOR);

 set("long",@LONG
這裡是蓮池的末端了, 再往東走會到天梟栽培嗜熱植物的
溫室, 而這裡仍然是栽培近水植物的地區, 你可以在這裡找到
你所需的藥材.
LONG
    );
 set("exits",([ "east":__DIR__"med6",
		"west":__DIR__"med2",
		"north":__DIR__"med4",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}