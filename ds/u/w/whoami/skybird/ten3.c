#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","黃土小路");

 set("long",@LONG
這是一條通往東方的黃土小路, 據說十萬大山群盜最常在
東邊出沒, 你凝目細望, 果然東邊遠處似乎有一座山寨, 如果
沒事, 還是趕緊回到滅骨峰吧....
LONG
    );
 set("exits",([ "northwest":__DIR__"ten2",
                "eastup":__DIR__"ten4",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

