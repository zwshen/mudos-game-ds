#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"木樁陣中"NOR);

 set("long",@LONG
 
  你覺得四周被木樁擠的換不過氣來, 既之發現這是你的心理作用,
可見對你已經感到一定程度的心慌意亂了....你心中不禁希望感快走
出這一個令人心慌了地方....這裡的[1;33m地上有二個腳印[0m...

��╲                                                 ╱��
��▕＿                                             ＿▏��
��▕ :▏                                         ▕: ▏��
��▕ :▏                                         ▕: ▏��
��▕￣                                             ￣▏��
��╱                                                 ╲��

LONG
    );
 set("exits",([ "west":__DIR__"wood3.c",
                "east":__DIR__"wood3.c",
                "north":__DIR__"wood3.c",
                "south":__DIR__"wood3.c",
    ]));

 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
