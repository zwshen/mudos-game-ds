#include <ansi.h>
inherit ROOM;
void create()
{

set("short",HIG"醉仙客棧"NOR);
set("long", @LONG
這是神木村中的客棧, 在這裡有許多的來客, 門口的上方掛了個金色
招牌上寫著『醉仙客棧』, 你只見到店小二忙著招呼客人, 這裡還有販賣
雜用品和食物.
LONG
);
set("light",1);
set("exits", ([                
        
        "west"  : __DIR__"road_8.c",
        "up"    : __DIR__"up_1.c",
   ]));

 setup();
}


