#include <ansi2.h>

inherit NPC;

void create()
{
	set_name(HIR"紅衣老人"NOR, ({ "red cloth old man", "man" }));
	set("level", 50);
	set("max_hp", 50000);
	set("max_ap", 50000);
	set("max_mp", 50000);
	set("str", 500);
	set("age", 5134);

	set("long", @long
在你眼前的這一位是一個滿身都穿著厚厚的紅色衣著的人，他的眼色
給你一種溫暖的感覺。
long);

	setup();
	add_money("silver", 100);
}

void init()
{
	object me, bag;

	me = this_player();

	if( !me ) return;

	if( !userp(me) ) return;

	if( !objectp(present("xmas2001", me)) )
	{
		bag = new(__DIR__"obj/bag");
		bag->move(this_object());
		command("say 年輕人,來參加滑雪橇比賽玩玩吧.\n");
		command("say 這裡附近有個小森林,你先去砍伐一些木頭回來\n");
		command("say 我就來幫你做隻木雪橇,你就用這個大袋帶木頭吧.\n");
		command("give bag to "+me->query("id"));
	}
	command("smile");
}