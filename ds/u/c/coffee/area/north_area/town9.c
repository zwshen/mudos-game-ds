#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"水泥路"NOR);
 set("long",@LONG 
這裡吹著強烈的風，讓你覺得開始冷了，加上嘯嘯的風吹聲
，讓你不禁開始緊張起來，不知道是要往回走，還是繼續前進，
前面有個彎道，裡面的入又更加狹窄，受到陽光的照射面積也明
顯變少了。
LONG
    );

       set("exits",([
       "east":__DIR__"town28",
       "south":__DIR__"town8",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}     
