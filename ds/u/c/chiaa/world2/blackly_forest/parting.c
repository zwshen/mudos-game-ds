//u/c/chiaa/world2/blackly_forest/parting.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "林中分岐小路");  
        set("long", @LONG
只見小路於此往東北、東北二方向,分了二條而行,
東北方是塊空地!而東南方是往沼澤方向前進,除此別無其他的路標,
實不知要往那一個方向行走才好!!
LONG    
        );

        set("exits", ([ /* sizeof() == 3 */
          "northeast" : __DIR__"vacancy2",     //林間空地2
          "west"      : __DIR__"causeway1",    //石子路1
          "southeast" : __DIR__"fen_road1",    //綠沼小路1
     ]));
        setup();
replace_program(ROOM);
}
