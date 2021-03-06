inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("梅龍鎮警衛",({"town guard","guard"}) );
	set("long",@LONG
一個警衛正在這裡監視著外來者的一舉一動。
LONG);
	set("age",31);
	set("level",18);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...

	set("talk_reply","嘿，只要安分守己我就不會為難你。");
	setup();

	carry_object(__DIR__"../wp/iron_sword_17")->wield();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_pants_7")->wear();
	carry_object(__DIR__"../eq/wood_armor_10")->wear();
	carry_object(__DIR__"../eq/leather_boots_6")->wear();
	carry_object(__DIR__"../eq/cloth_gloves_3")->wear();
	add_money("dollar",240);
}

void init()
{
	object ob = this_player();
	::init();
	if(this_object()->is_fighting()) return;
	if(!this_object()->visible(ob)) return;
	if( ob->query_temp("quest/malo_killer") > random(2) )
	{
		call_out("greeting",0,ob);
	}
	return;
}

void greeting(object ppl)
{
	if(!ppl) return;
	if(environment(ppl)==environment(this_object()))
	{
		command("say 身為警衛，我必須將兇手繩之以法。");
		kill_ob(this_player());
	}
	return;
}

void die()
{
	object killer;
	killer=this_object()->query_temp("last_damage_from");
	if(killer)
	{
		QUEST_D->delay_del_mytemp(killer,"quest/malo_killer",120);
	}
	::die();
}
