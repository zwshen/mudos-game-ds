#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","千嶙峰底");
 set("long",@LONG
眼前就是十萬大山中的次高峰 -- 千嶙峰了, 雖然還未登
頂峰, 但由此處向南方遠眺, 一條蜿蜒的巨龍在眼前出現, 想
必那就是大名鼎鼎的蟠龍城, 這裡往東是一條小路, 往北則通
往十萬大山深處.
LONG
    );
 set("exits",([ "southdown":__DIR__"ten1",
                "northup":__DIR__"ten7",
                "southeast":__DIR__"ten3",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

