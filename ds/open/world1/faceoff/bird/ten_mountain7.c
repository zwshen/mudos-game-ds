#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"狹道"NOR);

 set("long",@LONG
這裡是一條狹小的道路, 往東似乎有一個石門, 往西則可以
回到十萬大山中, 這條小小的狹道似乎已經很久沒有人走過了, 
你只有看到一些模糊不清的輪跡在你的腳下....
LONG
    );
 set("exits",([ "east":__DIR__"bird1", 
                "north":__DIR__"ten_mountain6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
