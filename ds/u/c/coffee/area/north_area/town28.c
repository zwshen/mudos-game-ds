#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"小路"NOR);
 set("long",@LONG
這裡吹著冷冽的風，不禁讓你開始發抖，這裡似乎愈來愈沒
有人了，只有一股恐怖的氣息，加上前方又好像有猛獸咆嘯的聲 
音，讓你開始覺得愈來愈恐怖了。
LONG
    );

       set("exits",([
       "north":__DIR__"town29", 
       "west":__DIR__"town9",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

