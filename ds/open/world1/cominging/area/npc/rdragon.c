#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIB"絞龍"NOR, ({ "rolling dragon","dragon","mob" }));
	set("long","傳說中只有在西方的世界出現的怪物。\n");

	set("race","野獸");
	set("level", 31+random(5));
	set("age", 50);

	set("limbs", ({ "龍頭","尾巴","鱗甲","觸角","前腳","後腳","背鰭" }) );
	set("verbs", ({ "bite", "claw","poke" }));

	set_temp("apply/attack", 9);
	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 35);
	set_temp("apply/armor", 12);

	set("combat_exp", 15000);
        setup();
	add_money("silver",2);
}