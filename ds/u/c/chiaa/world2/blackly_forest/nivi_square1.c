//u/c/chiaa/world2/blackly_forest/nivi_square1.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "廣場");
        set("long", @LONG
這裡是一個大廣場!平時是忍者村人們活動的地方,
要是有發生重大的事情,或是有特殊情況,
也可以當作一個集合的地點!!

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south"  : __DIR__"nivi_square2",         //廣場2
  "north"  : __DIR__"nivi_road2",           //忍村道路2
  "east"   : __DIR__"assembly_room",        //會議室
 ]));
       
        setup();
replace_program(ROOM);
}

