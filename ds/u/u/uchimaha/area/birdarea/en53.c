#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林﹝泥沼區﹞");
 set("long",@LONG
你來到東北澤林的泥沼區, 這裡的地上有些黏黏的
泥沼, 使你很難行動, 你不時聞到一股刺鼻的臭味, 讓
你感覺有點想吐.

LONG
    );
 
 set("exits",(["east":__DIR__"en54",
               "west":__DIR__"en52",
               "north":__DIR__"en51",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
