#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "��ù�T�a");
        set("long", @LONG
test�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shiro5", 
  "south" : __DIR__"shiro3", 
]));
        set("no_clean_up", 0);

        setup();
}
