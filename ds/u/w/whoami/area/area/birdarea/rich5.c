#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","富宅大廳");
 set("long",@LONG
你來到了獵狐村首屈一指的富豪的家裡, 這裡的佈置和陳設
沒有一樣不是貴的嚇人的, 看來住在這的真的不是等閒之輩, 在
你眼前的一位老翁似乎就是這裡的主人了
LONG);

 set("objects",([__DIR__"npc/richman" : 1,
                ]));
 set("exits",(["south":__DIR__"rich4",
              ]));  
 set("reborn",150); setup();
}        

