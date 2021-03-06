#include <ansi.h>
inherit NPC;

// 巨魔有再生的能力
void do_heal();

void do_combat();

void create()
{
  set_name( HIW "銀霜巨魔" NOR, ({"snow troll", "troll"}) );
  set("long",@LONG
巨魔（Troll）起源於北歐神話，是一種穴居性，相貌醜惡的吃人怪物，
身高可達九呎，體重五百磅。巨魔更是什麼肉都吃的恐怖食肉者，通常長的
非常孔武有力，橡膠似的皮膚覆蓋著漲股股的肌肉，好像稍微用點力，就能
把你給撕開了。
LONG
);
  set("age", 400);
  set("gender", "雄性" );
  set("level", 55);
        set("attack_merits","bar");

        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("block",100);
        set_skill("staff",100);
        set_skill("hammer",100);
        set_skill("unarmed",100);
            set("attitude", "aggressive");
        set("chat_chance", 30);
        set("chat_msg",({
        	(: do_heal() :),
        }) );

		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
					(:do_combat:), 

		}) );   
  setup();
	carry_object(__DIR__"obj/bloodstar-hammer")->wield();
	carry_object(__DIR__"obj/juniper-shield")->wear();

	if(random(5)==0)
		carry_object(__DIR__"obj/troll_chest_bone");
	if(random(5)==0)
		carry_object(__DIR__"obj/troll_head_bone");
	if(random(5)==0)
		carry_object(__DIR__"obj/troll_spinal_bone");

    carry_object(__DIR__"obj/troll_blood");
	set_temp("apply/armor",150); 
	set_temp("apply/damage",150); 
}

void do_heal() {
	if( !query_temp("weapon") ) command("wield hammer");
	if( query("hp") < query("max_hp") ) {
		message_vision( "$N身上的傷口因為再生能力的效果，慢慢地恢復了。\n" , this_object());
		receive_heal("hp", 800);
	}
}

void do_combat()
{
	object target;
	if( is_busy() ) return;
	target = select_opponent();
	if( !target ) return;
	if( query_temp("do_attack") ) return;
	if( !target->is_busy() && random(3) ) {
		message_vision(HIW "$N"HIW"一張口吹出了道冰冷的空氣，$n"HIW"被凍的直打哆嗦。\n" NOR, this_object(), target);
		target->start_busy(1);
	}
	message_vision(HIR "$N"HIR"怒吼連連，攻勢登時激進不少！！\n" NOR, this_object());
	set_temp("do_attack",1);	// mark 避免多次攻擊
	add_temp("apply/damage",50);
	add_temp("apply/hit",300);
		attack();
		attack();
	add_temp("apply/hit",-300);
	add_temp("apply/damage",-50);
	set_temp("do_attack",0);
}
