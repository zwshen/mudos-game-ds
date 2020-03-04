// Room: /u/a/acme/area2/t30.c

inherit ROOM;

void create()
{
        set("short","幽冥地窖[地下三層]");
	set("long", @LONG
這裡是幽冥地窖的地下三層，四周昏暗不明，陰風泠泠，你不禁打了個寒
顫，牙齒發出「喀∼喀∼∼」的撞擊聲響，在你眼前隱約能看見有左右二排的
大石柱，石柱圍成一個圓圈，在石柱中央卻有個雕像。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"t29",
]));
  set("item_desc", ([ /* sizeof() == 1 */
"雕像" : "這是一尊頗為怪異的雕像，雙腳開開呈馬步狀，但臉上表情卻頗為扭捏，真想給他[阿魯巴]。\n",
  ]) );
	set("no_clean_up", 0);

	setup();
}
void init()
{ 
         add_action("do_aruba","aruba");
}
int do_aruba(string arg)
{
          object me;
          me=this_player();
          if(arg != "雕像")
            return 0;
          else {
            message_vision("$N衝過去把雕像架住!!直往石柱拖去，只聽見雕像慘呼一聲，粉身碎骨，已成沙土。\n\n",me);
            message_vision("$N因拖得太使勁，一時停不住，一頭往石柱撞去，石柱應聲而倒，出現了個出口。\n",me);
message_vision("$N因頭腦受到強烈的撞擊，頭破了個大洞，鮮血不停的流出，$N頭昏眼花，搖搖欲墜。\n",me);
            set("exits",([
               "north" : __DIR__"t29",
               "southdown" : __DIR__"t31",
            ]) );
            me->receive_wound("head",10);
            return 1;
          }
}
int valid_leave(object me, string dir)
{
       if( dir=="southdown" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
        return ::valid_leave(me, dir);
}
