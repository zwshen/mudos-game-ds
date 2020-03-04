#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大通鋪"NOR);
set("long",@LONG
你發現這裡雖然住了不少的人, 但卻意外了乾淨和安靜, 這
裡少了客棧的塵囂, 取而代之的卻是一股安靜詳和的美好氣氛
讓你不禁想在這裡休息一下.
LONG
    );
 set("exits",([ "east":__DIR__"bed2",
                "south":__DIR__"walk7",
 ]));
 set("objects", ([__DIR__"npc/prayer" : 2,
             __DIR__"npc/bird_waiter":1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
