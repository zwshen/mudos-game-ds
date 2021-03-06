#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(GRN"食人魔法師"NOR, ({ "ogre mage","mage" }) );
        set("long",
        "食人魔中少見的法師。因為對他們而言，魔法是非常難懂的。\n"
        "但是對於這些成為黑暗僕人的食人魔，魔法反而成為他們可怕\n"
        "的力量。\n");
        set("race", "monster");
        set("gender","雄性");
        set("level",35);
        set("age",30);

        set("combat_exp", 5000);

        set("attitude", "aggressive");
        setup();
        set_living_name("fog-forest-war-monster");
        set("chat_chance", 20);
  	set("chat_msg", ({
	(: command("north") :),
	(: command("south") :),
	(: command("east") :),
	(: command("west") :),
	(: command("northeast") :),
	(: command("northwest") :),
	(: command("southeast") :),
	(: command("southwest") :),
	}));
}