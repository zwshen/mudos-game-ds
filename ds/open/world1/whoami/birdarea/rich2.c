#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","富宅長廊");
 set("long",@LONG
你來到了獵狐村首屈一指的富豪的家裡, 這裡的佈置和陳設
沒有一樣不是貴的嚇人的, 看來住在這的真的不是等閒之輩, 於
是你加快腳步向前走去, 希望能見到這的主人
LONG
    );
 
 set("exits",(["north":__DIR__"rich3",
               "out":__DIR__"rich1",
              ])); 
 setup();
 create_door("out","朱漆大門","enter",DOOR_CLOSED,"nokey");
}        

