// File: /d/duli_village/map_6_2.c
// Updated by tmr (Fri May  3 19:34:42 2002)

inherit ROOM;

void create()
{
          set("short", "漁村港口邊");
          set("long", @LONG
蔚藍的海洋正在你面前隨著太陽光蕩漾著，你自負要潛(dive)下海洋
戲水，倒也還有那份水性和體力。
LONG
          );
          set("exits", ([ /* 1 element(s) */
        "east" : __DIR__"map_6_3",
]));
          set("outdoors", "forest");
          set("map_long", 1);
         set("objects",([
           __DIR__"npc/wang-feng":1,
           ]) );



        setup();
}

void init()
{
        add_action("do_dive","dive");
}

int do_dive(string arg)
{
        object me=this_player();
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，沒空潛水。\n");
        message_vision("「噗通」一聲，$N躍往海面，隨即潛往海洋底下了....\n",me);
          me->move(__DIR__"sea_room");
        tell_room( environment(me),me->query("name")+"從海面上潛了過來。\n",me );
        return 1;
}


