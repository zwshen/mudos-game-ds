#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "¯ó¦a");
    set("long", "\n\n\n\n");
    set("light",1);
    set("exits", ([ /* sizeof() == 1 */
        "east"   : __DIR__"workroom",
    ]));
    set("outdoors","land");
    setup();
}

int valid_leave(object me, string dir)
{
    if( dir=="east" && !userp(me) ) return notify_fail("¸T¤î³q¹L¡C\n");
    return ::valid_leave(me, dir);
}
