#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內"NOR);
 set("long",@LONG 
這裡的地上十分凹凸不平，而且又十分狹窄，地上全是泥土
旁邊都是鐘乳石。前面的路好像有野獸活動的足跡，看著地上的
腳印，讓你猜不到到底是什麼怪物...
LONG
    );

       set("exits",([        
       "northwest":__DIR__"f1",
       "southwest":__DIR__"f4",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}
