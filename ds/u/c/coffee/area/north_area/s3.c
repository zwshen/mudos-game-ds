#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內-二層"NOR);
 set("long",@LONG 
你走著走著，突然，你覺得地上黏黏的、軟軟的，似乎會凹
陷下去。原來，這地上有一大片的泥巴，反而讓你走起路來更不
方便了。
LONG
    );

       set("exits",([        
       "north":__DIR__"s9", 
       "east":__DIR__"s2",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

