#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"小路"NOR);
 set("long",@LONG
這裡十分的荒涼，空氣也十分乾燥，因為這裡並不長有人來
，有時這裡也會傳來像是猛獸的吼聲，不禁讓人感到十分危險，
所以你還是趕緊回去比較安全吧。

LONG
    );

       set("exits",([
       "west":__DIR__"town29", 
       "north":__DIR__"town31",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

