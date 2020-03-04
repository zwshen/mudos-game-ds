#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","黃土小路");

 set("long",@LONG
你終於走到小路的盡頭了, 眼前是一個大大的寨門, 只見兩
旁都是一些巡邏中的嘍囉, 使你感到你的生命有些危險, 但是你
忽然發現有一個旗主倒在地上, 你或許可以...嘿嘿....
LONG
    );
 set("exits",([ "enter":__DIR__"ten6", 
                "west":__DIR__"ten4",
    ]));
 set("objects", ([__DIR__"npc/leader" : 1,
    ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}

