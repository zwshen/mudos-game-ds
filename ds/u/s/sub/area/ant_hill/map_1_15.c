// Room: /u/s/sub/area/ant_hill/map_1_15.c

inherit ROOM;

void create()
{
	set("short", "ÃÆ¥Þ¤J¤f");
	set("long", @LONG

LONG
	);
	set("current_light", 3);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_2_15",
]));
	set("map_long", 1);
	set("world", "undefine");

	setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="south" )
        {
                if(me->query("level")<25)
                {                        
                       return notify_fail("[0;1;33m¨[1mº[1m¸[1mÌ[1m¥[1mu[1m¦[1m³[1mµ[1m¥[1m¯[1mÅ[1m2[1m5[1m¥[1mH[1m¤[1mW[1m¤[1m~[1m¯[1mà[1m¶[1mi[1m¥[1mh[1m¡[1mC[0m\n");
                }
        }
        return ::valid_leave(me, dir);
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();
        if(!arg) return notify_fail("§A­n©¹­þ¸Ìª¦¡H\n");
        if (arg != "up") return 0;
        
        message_vision("$NÃk¦íÀð¾À¡AºCºC¦a©¹¤WÃkª¦¡C\n" ,me);
        me->move("/u/s/sub/area/village/tree1");
          tell_room(environment(me),me->query("name")+"«Ü¯T¯V¦aª¦¤F¤W¨Ó¡C\n",me);
        return 1;
}
