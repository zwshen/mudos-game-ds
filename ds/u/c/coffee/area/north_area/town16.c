#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"巷子"NOR);
 set("long",@LONG
來到這裡，兩旁的牆壁都是由磚塊組成，前面就是一家防具
店，從這裡就可以聽到再磨金屬的聲音，看來裡面的奇珍異寶應
該不少。

LONG
    );

       set("exits",([
       "northwest":__DIR__"town17",
       "southeast":__DIR__"town14",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

