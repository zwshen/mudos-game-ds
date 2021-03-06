#include <ansi.h>
inherit NPC;

void combat_ai() {
                if( is_busy() ) return;
                if( query_temp("do_attack") ) return;
                message_vision(HIC "月影烏瞳金絲虎眼露兇光，衝上來了幾步！！\n" NOR, this_object());
                set_temp("do_attack",1);    // mark 避免多次攻擊
                add_temp("apply/damage",50);
                add_temp("apply/hit",300);
                        attack();
                        attack();
                add_temp("apply/hit",-300);
                add_temp("apply/damage",-50);
                delete_temp("do_attack");
}

void create()
{
        set_name(HIY "月影烏瞳金絲虎" NOR,({"moon-shadow tiger","tiger"}) );
        set("title",CYN "" NOR);
        set("long",@LONG
這種老虎從兩眼到虎尾巴尖當中藏有一條金線，只有在星月清光
之下方可得見，乃是《雲物通譜》中有名有號的「月影烏瞳金絲
虎」。
LONG    
        );
        set("race", "tiger");    
      	set("title",HIG"無寧莊園"NOR);
        set("unit","隻");
        set("age", 600);
        set("level", 55);
        set("attitude", "aggressive");
        set("limbs", ({ "頭部", "腹部","胸部","巨爪","虎口","虎尾" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_hp", 5000);
        add("addition_armor", 90);
        add("addition_damage", 80);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (:combat_ai:), 
          }) );        
        setup();
//        set_living_name("_UNQUIET_MANOR_NPC_");
  	    set_temp("apply/bar", 3);
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
        set_temp("apply/damage",50);

	    if( random(100) < 50 ) carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_plate");
		carry_object(__DIR__"obj/moon-mask")->wear();
}


