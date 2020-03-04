// Room: /u/l/lestia/area/map_7_4.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "靈幻教-大殿走道");
        set("long", @LONG

你走在一條寬敞的大道之上，道上來往的人都清一色的穿著靈幻教的標
準白色制服，你知道你已經接近靈幻教的中心大殿了，大殿門口兩旁各有一
個雕滿了龍和鳳的鐵柱，中間站著兩位守衛在盤查要進入大殿的人，兩旁各
通往靈幻教徒才可使用的武道場。

LONG
        );
        set("no_clean_up", 0);
        set("world", "undefine");
   set("objects", ([ 
__DIR__"npc/guard1":2,
]));
 set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_5",
  "north" : __DIR__"map_6_4",
  "west" : __DIR__"map_7_3",
  "south" : __DIR__"map_8_4",
]));
        set("current_light", 1);

        setup();
}
int valid_leave(object me, string dir)
{
       object obj;
me = this_player();
 if( dir=="west")      //&& !wizardp(me))
        {
 if( me->query("class1") != "靈幻教" ) return notify_fail("教徒對你說: 你沒有天尊的同意不能進入。\n");
// }
}
                if( me->query_temp("killer") )
                {
                        message_vision(HIW"\n教徒對$N說道: 我們靈幻教不喜歡殺人兇手。\n"NOR,me);
                        return notify_fail("你必須等通緝時間過了之後才能去面見天尊。\n");
                }
/*
                if( me->query_temp("can_go") )
               {
                        message_vision(HIW"\n教徒仔細的檢查$N之後，讓$N過去了。"NOR,me);
               }
               if( me->query_temp("can_join_advmaster") )
               {
                        message_vision(HIW"\n教徒仔細的檢查$N之後，讓$N過去了。"NOR,me);
          me->delete_temp("can_join_advmaster");
}
*/
         return ::valid_leave(me, dir);
}


