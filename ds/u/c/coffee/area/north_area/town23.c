#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"庭院"NOR);
 set("long",@LONG
這裡是村長家門前的庭院，裡面種著許多花，看來村長
還蠻喜歡園藝的。前方好像還有路，但裡面卻好像有許多草
木，不之裡面有什麼東西。

LONG
    );

       set("exits",([
       "north":__DIR__"town25",        
       "south":__DIR__"town22",           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

