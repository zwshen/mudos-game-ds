#include <ansi.h>
inherit NPC;

void create()
{
	set_name("闇蜘蛛", ({"dark spider","spider"}) );
	set("long", "一隻黑色的大蜘蛛，這種蜘蛛不結網而是靠毒牙捕食獵物。\n");
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前足", "後足", "腹部" })); //受攻部位
	set("verbs", ({ "bite","claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 9);
	set("level",16);
	set_temp("apply/hit",-20);      //弱化命中率
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));

	setup();

}

int special_attack(object me,object victim,int hitrole)
{
	if(!me || !victim) return 0;
	if(random(5)) return 0;
	
	message_vision(HIW"$N伸出毒牙對著$n一陣亂咬，"NOR,me,victim);
	if(hitrole > 100)
	{
		victim->apply_condition("poison", victim->query_condition("poison")+3);
		message_vision(HIW"$n閃躲不及而被咬中，臉色發紫。\n"NOR,me,victim);
		victim->receive_damage("hp",20+random(20),me);
		return 1;
	}
	else message_vision(HIW"但被$n機警的閃了過去。\n"NOR,me,victim);
	return 0;
}
