// update 27/12
#include <ansi.h>   
inherit ROOM;
void create()
{
	set("short", HIC"ST．CakeMaster＠Steps"NOR); 
	set("long", @LONG     
這裡是一間很有名的蛋糕店，這裡賣的蛋糕十分好吃。而且到現在已
經是經營到第四代，歷史悠久，廚房裡更傳出蛋糕的香味。亦由於附近有
一個機械動物園，所以一到假日就有很多旅人來買蛋糕，而且口味繁多，
可以自己試試。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dst12",
]));
  set("objects",([
 __DIR__"npc/sword":1,
 ]));
set("light",1);
	set("no_clean_up", 0);
	setup();
}
void init()
{
 add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me;
        me=this_player();
        if (arg != "廚房") 
                   return 0;
        else {
                   message_vision(HIW"$N打開了門進了廚房。\n\n"NOR ,me);
                   me->move(__DIR__"cakeshop2");
                   tell_room(environment(me),me->query("name")+"走了過來。",me);
           return 1;
                 }
}