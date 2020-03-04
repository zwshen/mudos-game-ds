#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(YEL"哥布林守衛"NOR, ({ "goblin guard","guard" }) );
        set("long","洞穴入口的看守者。\n");
        set("race", "human");
        set("gender","雄性");
        set("level",20);
        set("age",25);

        set("combat_exp", 1000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIW"哥布林守衛似乎一直想要找同伴幫忙對付侵入者。\n"NOR,
	}));
        setup();
        carry_object(__DIR__"wp/longsword")->wield();

}
void die()
{
   	object me;
   	object env = load_object("/u/s/sdo/pwest/hill1.c");
   	if( !me = query_temp("last_damage_from") )
   	me = this_player();
   	if( !me )
   	{
     		::die();
     		return;
   	}
   	env->call_monster();
   	message_vision(
   	"\n\n$n"HIY"發出一聲淒厲的叫聲，驚動了山洞裡的怪物們！\n\n"NOR,me,this_object());
   	::die();
   	return;
}