#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內-二層"NOR);
 set("long",@LONG 
這裡突然跑出數隻野獸，開始發瘋似的亂攻擊你！讓你反應
不太過來，加上地上的泥沼地，讓你的行動更加的不方辯了，不
知道是否還能出的去••
LONG
    );

       set("exits",([        
       "north":__DIR__"s6", 
       "west":__DIR__"s9", 
       "east":__DIR__"s10",
       "south":__DIR__"s2",           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

