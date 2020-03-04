#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", "一個基本的房間") ;
   set ("long", "這是一個非常" + "簡單的房間。\n") ;
   set ("exits", ([
                    "west":__DIR__"skinroad2.c",
                    "east":__DIR__"desert1.c",
   ])  ) ;
       
        set("outdoors","desert");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
