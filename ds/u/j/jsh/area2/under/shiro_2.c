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
  "south" : __DIR__"shiro_1",  
  "east" : __DIR__"shiro_3",]));
        set("no_clean_up", 0);

        setup();
}

