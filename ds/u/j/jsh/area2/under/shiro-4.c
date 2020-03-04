#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "­×Ã¹¸T¦a");
        set("long", @LONG
test¡C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"shiro-3", 
]));
        set("no_clean_up", 0);

        setup();
}

