#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"抓狂大廳廳"NOR);
        set("long", @LONG
這訴一個大廳....很普通ㄛ....
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"workroom2",
        "east" : __DIR__"workroom4",
        "north" : __DIR__"quest_room",
        "area" : __DIR__"sexking/map_1",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
call_other( "/obj/board/sexking_b.c", "???" );
}


