#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", HIC"古墓" HIB"迷宮陣"NOR);
        set( "long", @LONG
 這裡是古墓為了防止敵人更進一步的侵略內墓，所特別設計的迷宮陣
 ，來到這裡，只能說要全靠運氣了。
 四週的壓迫感讓你感到很無助。
LONG
);
        set("hide_exits", ([ /* sizeof() == 7 */
                  "east" : __DIR__"room5",
                  "west" : __DIR__"room5",
                  "north" : __DIR__"room5",
                  "south" : __DIR__"room5",
                  "northeast" : __DIR__"room5",
                  "northwest" : __DIR__"room5",
                  "southwest" : __DIR__"room5",
        ]));
        set("objects",([
                   __DIR__"statue" : 1,
                 ]) );
        set("light",0);
        set("no_map",1);
        set("no_clean_up", 0);
        setup();
}

