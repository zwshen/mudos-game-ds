#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟天市堂"NOR);

 set("long",@LONG
這裡就是二十年前名震江湖的天市堂, 天梟的大小教務都
是經由此處向教主報告, 宛如古代的黃帝早朝, 也因為如此而
遭到官府的離間, 不過今日已經沒有古時的盛況, 這裡現在除
了天梟攻武一派的教主以外, 東西方的迴廊也通往各處的重要
設施.往北則是有名的天梟聖泉....
LONG
    );
 set("exits",([ "east":__DIR__"eastroad1",
                "west":__DIR__"westroad1",
            "north":__DIR__"bird6",
                "south":__DIR__"bird2", 
    ]));
 set("objects", ([__DIR__"npc/skybird_master" : 1,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
