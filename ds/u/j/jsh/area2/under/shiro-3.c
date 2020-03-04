#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "­×Ã¹¸T¦a");
        set("long", @LONG
test¡C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"shiro-4", 
  "east" : __DIR__"shiro-2", 
]));
        set("no_clean_up", 0);

        setup();
}

