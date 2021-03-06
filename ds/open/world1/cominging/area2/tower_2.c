#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "守衛塔中"HIY"倉庫"NOR);
	set("long", @LONG

你一步步的走上旁邊的石梯，一陣陣的聲響隨著你的腳步而響起，
不知道衛兵有沒有注意到，這裡是守衛塔之中，這裡沒有什麼東西，一
個走廊，旁邊有幾扇往外的窗子，看的到遠處的滄縣和南方的森林盜賊
窩，旁邊放著些煙火，和一些弓、箭。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"tower_3.c",
  "down" : __DIR__"tower.c",
]));
	set("objects",([
  __DIR__"npc/partol_g.c": 2,
]));
	set("item_desc",([
  "窗子" : "這是一扇窗子，可以觀望到遠處滄縣，也可以看得到南方森林的盜賊窩，而便於守衛。\n",
  "石梯" : "一塊塊用石頭做成的梯子，上面鋪著一層稻草。\n",
  "煙火" : "一堆堆放好的煙火，是在外敵入侵時放用的。\n",
  "弓" : "一些用木做成的弓，但是有些都已蟻蟲給食個腐爛。\n",
  "箭" : "放在地上一團團放在一起的箭，可能可以拿起來吧。\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	set("level","tower_2");
	setup();
}

void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	object me, arrow, guard;

	me = this_player();
	arrow = new(__DIR__"npc/obj/arrow2.c");

	if( arg!="箭" && arg!="arrow" ) return 0;
	arrow->move(me);
	message_vision("$N撿起了地上的一些箭。\n",me);
	if( !living(guard=present("patrol guard",this_object())) ) return 1;
	message_vision("$N大喝：幹啥！偷撿軍庫軍火？！\n",guard);
	guard->kill_ob(me);
	me->kill_ob(me);
	return 1;
}