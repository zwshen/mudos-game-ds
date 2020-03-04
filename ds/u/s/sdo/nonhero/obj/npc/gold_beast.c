#include <ansi2.h>
#include <path.h>
inherit NPC;
void create()
{
        set_name(HIY"金之守護獸"NOR, ({ "gold beast","beast" }) );
        set("long","無名英雄之墓的守墓獸之一，性情殘暴。\n");
        set("race", "野獸");
        set("gender","雄性");
        set("level",30);
        set("age",200+random(20));
	set("attitude", "aggressive");

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIR"守衛石獸低吼一聲，對於你的侵入非常憤怒！\n"NOR,
	}));
        setup();

}

void die()
{
	object obj,room;
	room=load_object(SDO_PAST+"nonhero/grav5");
  
	message_vision( "$N"+HIY "臨死前，週遭出現一陣煙霧，煙霧逐漸組合成一支長槍。\n" NOR ,this_object() );

	obj=new(__DIR__"obj/rust_pike.c");
	obj->move(environment(this_object()));
	room->delete_temp("opened");

	::die();
	return;
}