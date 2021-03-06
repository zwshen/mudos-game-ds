#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "山谷空地");
        set("long", @LONG
你正在一處不知名的山谷中，你四周圍環繞著削高入雲的山壁，除了
剛鑽進來的山縫之外，實在再找不到出口。山谷中惠風和暢，吹在身上頗
有醉人之意，谷中尚有數株果樹、野花，偶而也耳聞關關烏嗚。
LONG
        );

	set("item_desc",([
    "山壁":"你仔細著看了看山壁，赫然發現山壁有個爪形印痕。\n",
	"爪形印痕":"爪形印痕其深入山壁數寸，不似天然而成，似乎是種能啟動的機關。\n",
	]) );
        set("exits", ([ /* sizeof() == 1 */
          "east" : __DIR__"rift1",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
	set("objects",([
	   __DIR__"npc/monkey":1,
	]) );
        setup();
}
void init()
{
	add_action("do_put","put");
}

int do_put(string arg)
{
	object me,claw;
	me=this_player();
 
      if(!arg || arg!="fist into 爪形印痕") return 0;
        if(!objectp(claw=present("sun-snow-fist",me) ) )
		return notify_fail("你身上並沒有合印痕的爪形東西。\n");
	message_vision("$N拿起一個發著黃色光芒的爪放入山壁中的爪形印痕。\n",me);
     message_vision(HIY "忽然一條金色繩子從山壁中捲住了$N，隨即快速沿著峭壁而上！！\n" NOR,me);
  me->delete_temp("jump-hole");
	me->move(__DIR__"temp-room");
	me->start_busy(2);
	call_out("show",3,me);
	return 1;	 
}

void show(object me)
{
	if(!me) return;
if (me->query_temp("jump-hole")==1) return 0;

	tell_object(me,"咻著一聲，你重重地摔在一塊雪地。\n");
	me->move(__DIR__"ghat1");
     tell_room(environment(me),me->query("name")+"陡著忽然摔在你面前。\n",me);
	return;
}
