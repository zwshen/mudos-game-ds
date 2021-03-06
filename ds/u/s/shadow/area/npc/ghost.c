/**
 *	Shadow's mob - 紅衣女鬼
 */
#include <ansi.h>
#define SHADOW_GRAVEYARD "/u/s/shadow/area/"

inherit NPC;

void create()
{
	set_name(HIR"紅衣女鬼"NOR, ({ "red-cloth ghost", "ghost" }) );
	set("level", 50);		
	set("long", @LONG
    披頭長髮，身上披著一襲已褪色大紅色衣衫的女鬼。哀怨的眼神
中彷彿訴說生前有著說不盡的哀屈。但隨即眼中兇光閃爍，怨毒的神
情讓你不寒而慄，似乎要將你生吞活剝似地！
LONG
	);
	set("title", HIG"義莊"NOR);
	set("age", 83);
	set("evil", 0);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("combat", 100);
	
	set("chat_chance_combat", 15);
	set("chat_msg_combat",({
		HIR"紅衣女鬼指甲突然暴長，向你瘋狂攻擊。\n"NOR,
		HIR"紅衣女鬼突然用頭髮纏住你的手腳，讓你動彈不得。\n"NOR,
	}));
	
	setup();
	add_money("coin", 800);
	set_living_name("GraveyardWar");
}

void init()
{
	::init();
	if(!this_object()->visible(this_player())) return;
}

void die()
{
	int i;
	object ob, room;
	if( !ob = query_temp("last_damage_from") )	ob = this_player(1);
	if( !ob ) {
		::die();
		return;
	}
	ob->add("popularity", 3);
	message("world:world1:vision", HIR"\n\t紅衣女鬼對著"+ob->name(1)+HIR+"尖叫嘶吼 ∼ "+" 我 好 恨 啊 ∼\n\n"NOR, users());

	/* 開啟祠堂的 south 出口 & recall */
	room = load_object(SHADOW_GRAVEYARD"graveyard23");
	room->set("no_recall", 0);
	room->set("exits",([
		"south": SHADOW_GRAVEYARD"graveyard22",
	]));
	
	::die();
	return;
}
