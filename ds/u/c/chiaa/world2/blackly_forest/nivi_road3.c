//u/c/chiaa/world2/blackly_forest/nivi_road3.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
你正走在忍者村的一條道路,路上的行人對你這個 
意外的訪客,似乎有存著很高的警戒心和好奇心!!
西邊不遠處可看到一間商店!!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "south"  : __DIR__"nivi_road4",        //忍村道路4
    "east"   : __DIR__"nivi_road2",        //忍村道路2
    "west"   : __DIR__"store",             //商店
]));
       
            setup();
replace_program(ROOM);
}
