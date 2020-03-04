//u/c/chiaa/world2/blackly_forest/fen_road1.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "沼澤小路");
        set("long", @LONG
你正走在一條泥濘小路,稍不注意便會陷在其中,
空氣中飄散著惡臭難聞的沼氣,讓人相當不舒服!
要是不小心吸入過多的沼氣,只怕早已昏迷不省人事!
往東不遠處可看到一處沼澤。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
     "east"       : __DIR__"fen1",         //沼澤1
     "south"      : __DIR__"fen_road2",    //沼澤小路2
     "northwest"  : __DIR__"parting",      //分歧路
]));
       
        setup();
replace_program(ROOM);
}
