#include <room.h>
inherit ROOM;
void create()
{
 set("short","小路");
 set("long",@LONG
你往北走來到了這兒, 這裡的草叢越來越稀疏, 同時
青蛙的鳴叫聲也安靜了下來, 你往北方一看, 看到了一片
通向雲霄的峭壁.
LONG
    );
 
 set("exits",(["north":__DIR__"bird1",
               "south":__DIR__"en44",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
