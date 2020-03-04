#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你看到這兒的植物比剛才更茂密, 而且還多了幾株
灌木, 這裡的空氣非常的清新, 令你不想離開, 想多待
幾下, 不過聽說這裡危機重重, 還是趕快走吧.
LONG
    );
 
 set("exits",(["northwest":__DIR__"en41",
               "southeast":__DIR__"en39",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
