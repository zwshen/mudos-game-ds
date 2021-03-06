//charm

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("驅風符",({"wind seal","seal"}) );
	set("long",@LONG
一張道士用來作法的符，上頭用硃砂寫了數行符文，字裡行間透露
著一股法力。通常這種屬於初入道家的道士的符咒，本身即有相當的法
力，就是一般人也能念咒施法（charm），只是法術效果不大。
LONG
	);
	set_weight(50);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","張");
		set("value",500);
	}
	setup();
}

void init()
{
	add_action("do_charm","charm");
}

int do_charm(string arg)
{
	object me,tar,*enemy;
	int i,t,damage;

	me=this_player();
	if(!me->is_fighting() ) return notify_fail("你並沒有在戰鬥中。\n");
	if(me->is_busy() ) return notify_fail("你正忙著，沒空念法施咒。\n");

	enemy=me->query_enemy();
	t=sizeof(enemy);
	message_vision(
CYN "$N點燃一張驅風符，口中喃喃自語，陡地祭地一陣疾風！！\n" NOR
	,me);
	
	for (i=0;i<t;i++)
	{	
	if (i>2 ) continue;
	tar=enemy[i];
	damage=me->query_int();
	damage-=tar->query_shield()+tar->query_int();
	if (damage<=0) damage=1;
	if (damage>50) damage=50;

		if(tar->is_busy()
		   || random(tar->query_dex()+tar->query_int() ) < random(me->query_dex()+me->query_int() )  )
		{
		message_vision("一陣疾風如刀劍般在$N身上造成數處割傷。\n",tar);
		tar->receive_damge("hp",damage);
		COMBAT_D->report_status(tar);
		}

	}
	message_vision("\n$N手上的符咒燒成只剩下灰燼了。\n",me);
	destruct(this_object() );
	return 1;
}