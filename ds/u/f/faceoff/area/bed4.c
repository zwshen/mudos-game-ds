#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大通鋪"NOR);
set("long",@LONG
這裡是天梟提供來訪者休憩的東男邊床位, 你發現這裡休
憩大部份是十萬大山的遊客, 也許你可以問一問他們十萬大山
的景點, 相信他們一定樂意告知..
LONG
    );
 set("exits",([ "north":__DIR__"bed3",
            "west":__DIR__"walk5",
]));
 set("objects", ([__DIR__"npc/traveller" : 3,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
