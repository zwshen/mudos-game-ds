#include <ansi.h>

inherit ROOM;
inherit DOOR;
#include <room.h>

void create()
{
   ::create() ;
   set ("short", "一個基本的房間") ;
   set ("long", "這是一個非常" + "簡單的房間。\n") ;
   set ("exits", ([
                    "south":__DIR__"skyevil2.c",
                    "up":__DIR__"infinite10.c",
]) ) ;
create_door("up",HIM"天妖門"NOR,"down",DOOR_LOCKED,"skyevilkey");


       

        set("no_clean_up", 0);
        set("light", -1); 

        setup();

}

