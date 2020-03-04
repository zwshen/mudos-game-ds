#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你來到了東北澤林的深處, 也就是所謂的森林沼澤
區, 你感覺到這裡的景色和之前的大不相同, 有一種詭
異的氣氛, 這條路通往西方.

LONG
    );
 
 set("exits",(["west":__DIR__"en51",
               "northeast":__DIR__"en49",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
