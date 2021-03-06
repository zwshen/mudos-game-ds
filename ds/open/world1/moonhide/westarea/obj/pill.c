/*	File : "/open/world1/moonhdie/westarea/obj/pill.c"		*
 *	Author : Alickyuen@DS on 12/2001			*/

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

int random_case();
int poison();
int unconcious();

void create()
{
	set_name(HIW"六轉還合丹"NOR, ({ "six around pill","pill" }) );
	set_weight(50);
	set("long", @long
這一粒是九天玄女集天下之精華，化致而成的仙藥，據說共有六種功
用，但沒人知道其真正功效，且說每次吃時的功效都不同，若要試吃
，請先有好心理準備！
long);
	set("unit","顆");
	set("value", 10);      	
	set("food_remaining",1);
	set("changed", 0);

	setup();
}

void init()
{
	:: init();

	if( !this_object()->query("changed") )	random_case();
}

int random_case()
{
	this_object()->set("changed", 1);

	switch(random(6))
	{
		case 0:
			this_object()->set("heal_hp", 1000);
			return 1;
		break;
		case 1:
			this_object()->set("heal_ap", 1000);
			return 1;
		break;
		case 2:
			this_object()->set("heal_mp", 1000);
			return 1;
		break;
		case 3:
			this_object()->set("heal_hp", 1000);
			this_object()->set("heal_mp", 1000);
			this_object()->set("heal_ap", 1000);
			return 1;
		break;
		case 4:
			this_object()->set("heal_hp", 1);
			this_object()->set("food/function", (: poison :));
			return 1;
		break;
		case 5:
			this_object()->set("heal_hp", 500);
			this_object()->set("heal_mp", 500);
			this_object()->set("heal_ap", 500);
			return 1;
		break;
		default:
			return 1;
		break;
	}
}
	

int poison()
{
	object me = this_player();

	message_vision(HIR"$N突然面色變黑，像是中毒了！\n"NOR, me);

	me->apply_condition("poison", me->query_condition("poison")+ (me->query("level")+random(me->query("level"))) );

	return 1;
}

int unconcious()
{
	object me = this_player();

	message_vision(HIR"$N突然面色一變，就昏倒在地上了......\n"NOR, me);

	me->unconcious();

	return 1;
}
