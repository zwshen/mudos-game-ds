
inherit NPC;
void create()
{
    set_name("巨蟒", ({ "boa constrictor", "boa", "constrictor" }) );
    set("race", "野獸");
    set("age", 80);
    set("long", "一條兩丈來長的蟒蛇，渾身黑黝黝的。\n");
    set("attitude", "aggressive");

    set("limbs", ({ "頭部", "身體", "七寸", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    set("combat_exp", 300000);
    set("no_get","怪蟒對你而言太重啦，你無法拿動");
	  
	  set_skill("dodge", 200);
	  set_skill("parry", 200);
    set_temp("apply/attack", 50);
    set_temp("apply/defense", 50);
    set_temp("apply/damage", 50);
    set_temp("apply/armor", 100);
    set_temp("apply/dodge", 100);
	setup();
}

 
void die()
{
	object ob;
    	message_vision("$N垂死掙扎了幾下就不動了。\n", this_object());
        ob = new(__DIR__"obj/boafur.c");
	ob->move(environment(this_object()));
	destruct(this_object());
}

/*
int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + random(3));
        return 0;
}
*/
