#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"巷子"NOR);
 set("long",@LONG
來到這裡，你發現前面有家武器店，從這裡就可以看見武器
閃閃發光，你不禁想進去逛逛，但是如果進去逛了，就要帶點錢
，買把武器吧！

LONG
    );

       set("exits",([
       "northeast":__DIR__"town27",
       "southwest":__DIR__"town15",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     


