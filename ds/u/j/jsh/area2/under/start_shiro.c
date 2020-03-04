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
  "north" : __DIR__"shiro2",
]));
        set("light",1);
        set("no_clean_up", 0);

        setup();
}

