#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
	([	"action":		"$N張大嘴巴朝著$n的$l一陣猛咬",
		"attact_type":  "bar",	// 設定技能的攻擊種類
					// 種類有 生物(bio) 獸性(bar)
					// 魔法(wit)心靈(sou)科技(tec)
		"damage_type":	"咬傷",
	]),
	([	"action":		"$N突然往$n的方向撞了過去",
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
	([	"action":		"$N對準$n的$l猛然吐出一道寒氣",
		"attact_type":  "bio",
		"damage_type":	"腐蝕",
	]),
    ([  "action":       "$N憤怒的舞動利爪狂掃$n的$l",
		"attact_type":  "bar",
		"damage_type":	"抓傷",
	]),
});

void do_clean();

void create()
{
        set_name(HIW"冷月"NOR,({"cold moon monster", "monster" }) );
	set("long",@LONG
冷月為一渾身雪白慘淡的魔獸，身高三尺有餘，其性喜寒，兩眼深藍
帶絲絲白線，細而長的呼吸凍結了四周的空氣，全身銀毛戎戎地不似人間
物，無人知道冷月從何而生，只知古老相傳的一句詩：「遇妖遇魔仍可生
，冷月寒日命難脫。」

LONG
);
        set("limbs", ({
		"頭部",	"頸部",	"胸口",	"背後","腰間","腹部","前爪","後腿","尾巴",
	}) );
        set("title","「魔獸」");
        set("age",500+random(99));
        set("level",66);
        set("gender","雄性");
        set("race","monster");
        set("attitude", "aggressive");
        set("chat_chance", 13);
        set("chat_msg",({ 
  	(: this_object(), "random_move" :),
  	"冷月發出陣陣的嘶吼聲。\n",
  	"冷月身上的冰霜掉在地上發出喀喀的聲音。\n",
  	"附近突然吹起一陣寒風凍的讓人喘不過氣來。\n",
  	"附近突然吹起一陣寒風凍的讓人喘不過氣來。\n",
}));
	set("addition_armor",70);
	set_skill("mob_bite", 84);
	set("addition_armor",92);
    set("Merits/wit",3);
	add("apply/hit",60);
	set("addition_damage",78);
        set("chat_chance_combat", 42);
        set("chat_msg_combat", ({
	        (:command("exert mob_bite moonmonster"):),
	        (:command("exert mob_bite moonmonster"):),
	        (:command("exert mob_bite moonmonster"):),
	        (:command("exert mob_bite moonmonster"):),
	        (: this_object(), "random_move" :),
       	 }) );
	set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
	carry_object(__DIR__"wp/moon_tooth.c")->wield();
}
mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

void die()
{
	object ob;
	
	if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
	if( !ob )
	{
		::die();
		return;
	}
	message("world:world1:vision",
	CYN"\n  [小道消息] 使人聞風喪膽的冷月獸終於被"+ob->name(1)+"殺死了。\n\n"+NOR,users());
	ob->add("popularity",2+random(3)); //聲望
	::die();
	//destruct(this_object());
	return;
}
