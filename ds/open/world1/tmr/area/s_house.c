// Room: /u/t/tmr/area/s_house.c
#include <room.h>
#include <path.h>

inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "石屋內");
        set("long", @LONG
這是一間用石塊堆積而成的一間小屋，屋內桌椅几榻皆用竹編而成，
只設一門一窗，陳設極為簡單。細看地板石磚中皆有腳印，深及兩寸，四
面牆壁滿佈小洞，殘破不堪。
東牆上有塊匾額，上頭寫著威武的一句話：「劈掛參八極，英雄歎莫及」。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"glade",
   "west": TMR_PAST"bagi/rift",
]));
        set("no_clean_up", 0);
	set("valid_startroom",1);
	set("objects",([
	__DIR__"npc/master" : 1,
	]) );
	set("light",1);
        setup();
      create_door("west", "後門", "east", DOOR_CLOSED);
}
