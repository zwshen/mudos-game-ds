//u/c/chiaa/world2/little flower_island/champaign1.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIG"平原"NOR);
        set("long",@LONG
這裡是一望無際的大草原,陣陣的風把草吹的有如
大海的波浪,一陣一陣向你襲來,煞是好看!!
你感覺清涼微風吹拂著你的身體
令人心曠神怡!!


LONG
        );
        set("exits", ([ /* sizeof() == 3 */
       "west"         : __DIR__"champaign2",    //平原2
       "east"         : __DIR__"brae3",         //山坡3
       "southeast"    : __DIR__"champaign5",    //平原5
      ]));
       
            setup();
replace_program(ROOM);
}
