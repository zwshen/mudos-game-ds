#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(HIY"Naboo Starfighter"NOR,({"Naboo Starfighter","fighter"}));
	set("long","這是由Naboo研製出來的飛船。\n");
	set_weight(3000000);
	set_temp("apply/damage",10);
	set_temp("apply/armor", 15);
	set("no_get",1);
	set("amount",1);
	set("unit","部");
	set("value",10000);
	setup();
}
void init()
{
	add_action("do_ascend","ascend");
	add_action("do_descend","descend");
}

int do_descend()
{
	object me;
	string *name;

	me=this_player();
	if(!me->query_temp("marks/ascend"))
	return notify_fail("你已經離開飛船了。\n");
	message_vision("$N隨著"+this_object()->name()+"的緩降梯降了下來。\n",me);
	me->delete_temp("marks/ascend");
	me->delete_temp("apply/short");
	move(environment(me));
	return 1;
}

int do_ascend()
{
	object me;

	me=this_player();
	if(me->query_temp("marks/ascend"))
	return notify_fail("你已經在飛船n。\n");
	message_vision("$N進入了"+this_object()->name()+"的機艙。\n",me);
	me->set_temp("marks/ascend",1);
	me->add_temp("apply/short",({me->short()+HIY"(正指控制著"NOR+this_object()->name()+HIY")"NOR}));
	move(me);
	return 1;
}


