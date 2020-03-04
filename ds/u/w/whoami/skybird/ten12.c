#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","羊腸道");

 set("long",@LONG
你終於跨出了羊腸道, 從這裡往西北走會到十萬大山中人口
最稠密的農耕區, 往東則通往分裂後的天梟冶藥一派及他們的植
藥園.
LONG
    );
 set("exits",([ "southwest":__DIR__"ten11",
                "east":__DIR__"pill1",
    ]));
 set("objects", ([__DIR__"npc/soldier" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

