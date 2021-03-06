// ㄒㄧㄚ  ㄅㄧㄠ
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "颬颮客棧");
	set("long", @LONG
這是步靈城中的颬颮客棧，在這裡有大群的來客，似乎可以比大步
靈城的中央廣場一般的大，颬颮客棧是最近新開的客棧，但來客卻湧湧
而入，可能是位居龍鳳穴之關係，在這的人聲幾乎可以把你的耳膜給震
破掉，好像有幾位你認識的人物，樓上是來客的休息房，在每桌桌上都
放了一個木製的標誌，在這有放著一個告示牌，若是你有跟小二付錢休
息的話，可以在這裡歇息靜坐(rest)。
LONG
	);
	set("exits", ([
  "northeast": __DIR__"kitchen.c",
  "west" : __DIR__"bnorth.c",
  "up" : __DIR__"hotel2f.c",
]));
	set("objects", ([
  __DIR__"npc/waiter" : 1,
  __DIR__"npc/obj/sign.c" : 1,
]));
	set("item_desc",([
  "標誌" : "這些標誌是為了幫忙小二幫忙送菜而用的，不過常常被一些無聊的人破壞。\n",
]));
	set("light", 1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("map","hotel");
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir!="up" )return ::valid_leave(me, dir);

	if( dir=="up" && me->query_temp("sleep") <=0 || !me->query_temp("sleep") )
		return notify_fail("你還沒向店小二訂房間！\n");

	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_rest","rest");
}

int do_rest(string arg)
{
	object me;
	me = this_player();
	if( me->is_busy() )
		return notify_fail("你還在忙吧, 應該沒時間去歇息. \n");
	if( me->query_temp("rest") <= 0 )
	{
		write("你所能歇息的次數已用光了！\n");
		return 1;
	}
	if( me->query_temp("is_busy/sitting") )
	{
		write("你正在靜坐。\n");
		return 1;
	}
	message_vision("$N在這裡找了一個位子坐了下來，開始靜坐了起來。\n",me);
	me->add_temp("rest",-1);
	me->set_temp("is_busy/sitting","你正在靜坐。");
	me->start_busy(10);
	call_out("sleep",0,1,me);
	call_out("sleep",10,2,me);
	return 1;
}

void sleep(int c,object me)
{
	switch(c) {
	case 1:
		tell_object(me,HIC"你漸漸開始進入心空的狀態，什麼都不想．．\n"NOR);
		me->receive_heal("ap",me->query_con()*2);
		me->receive_heal("mp",me->query_int()*2);
	break;

	case 2:
		tell_object(me,HIG"你漸漸睜開眼睛，把心給收了回來。\n"NOR);
		me->receive_heal("ap",me->query_con()*2);
		me->receive_heal("mp",me->query_int());
		me->delete_temp("is_busy/sitting");
	break;
	}
}