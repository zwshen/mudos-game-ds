#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","東戶政部");
set("long",@LONG
這裡是海政部的東戶政部, 專門辦理一切的移居事務, 在房
間中央的人就是東戶政官了
LONG
    );
 set("exits",([ "south":__DIR__"seacoun14",
]));
 set("objects", ([__DIR__"npc/east_master" : 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
