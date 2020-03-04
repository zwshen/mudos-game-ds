#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(HIC"風之守護獸"NOR, ({ "wind beast","beast" }) );
        set("long","無名英雄之墓的守墓獸之一，行動敏捷。\n");
        set("race", "野獸");
        set("gender","雄性");
        set("level",30);
        set("age",200+random(20));

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("dex", 60);
        set("combat_exp", 30000);
	set_skill("dodge", 100);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIR"守衛石獸的迅速移動，使你有些頭昏眼花。\n"NOR,
	}));
        setup();

}

void die()
{
	object ob,obj;
  
	message_vision( "$N"+HIC "臨死前，週遭出現一陣煙霧，煙霧逐漸組合成一雙脛甲。\n" NOR ,this_object() );

	obj=new(__DIR__"obj/rust_leggings.c");
	obj->move(environment(this_object() ) );

	::die();
	return;
}