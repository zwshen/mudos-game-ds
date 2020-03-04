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
  "north" : __DIR__"shiro3", 
  "south" : __DIR__"start_shiro",]));
        set("light",1);
        set("no_clean_up", 0);

        setup();
}

