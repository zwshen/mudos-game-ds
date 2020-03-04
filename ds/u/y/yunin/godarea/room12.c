#include <ansi.h>
#include <path.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short", HIW"Á¼¤§«Î"NOR);
    set("long", @LONG
¤@¤Á³£¬OÁ¼¡A¨S¦³©Ò¿×ªº¬O»P«D¡A¹ï»P¿ù¡C¦b§Aªº¥k¤âÃä¦³­Óµo
¥úªº¥ÛÀY¡A[0;1;36m¬[1mÝ[1m¤[1m@[1m¤[1mU[1m([1ml[1mo[1mo[1mk[1m)[0m»¡¤£©w·|¦³¥X¥G¹w®Æªº¨Æ±¡µo¥Í¡C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  
  "µo¥úªº¥ÛÀY" : "[0;1;37m³[1mo[1m¬[1mO[1m¯[1md[1m¶[1mÇ[1m¤[1mw[1m¤[1m[[1mª[1mº[1m¥[1mÛ[1mÀ[1mY[1m¡[1mA[1m¥[1m@[1m¤[1mH[1mº[1mÙ[1m¥[1m¦[1m¬[1m°[1m¯[1m«[1m¤[1m§[1m¥[1mÛ[1m¡[1mA[1m¦[1mp[1mª[1mG[1m§[1mA[1mÄ[1m²[1mº[1mN[1m¬[1mÝ[1m¬[1mÝ[1m([1mt[1mo[1mu[1mc[1mh[1m)[1m»[1m¡[1m¤[1m£[1m©[1mw[1m·[1m|[1mµ[1mo[1m¥[1mÍ[1m¤[1m@[1m¨[1mÇ[1m©[1m_[1m§[1m®[1mª[1mº[1m¨[1mÆ[1m³[1má[1m¡[1mC[0m ",
]));
        set("world", "past");
                set("exits", ([ /* sizeof() == 1 */
  "out" : "/u/y/yunin/godarea/room5",
]));  
   set("no_clean_up", 0);

        setup();
}      
void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="µo¥úªº¥ÛÀY" ) return 0;
        message_vision(HIR"§AºN¤F³o­Ó©_©Çªº¥ÛÀY¡A©¿µM­¸¤W¤F¤Ñ¡C \n"NOR,me);
        me->move(__DIR__"room13");
          tell_room(environment(me),me->query("name")+HIR"©¿µM­¸¤W¤F¤Ñ¡C\n"NOR,me );
return 1;
}

