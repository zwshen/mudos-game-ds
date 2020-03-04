#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "¤K¤j­{");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"room6",]));
        set("no_clean_up", 0);

        setup();
}


