//buddha war 大頭目 如來佛

#include <ansi.h>

inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N揮拳攻擊$n的$l",
                "attact_type":  "sou",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N往$n的$l一抓",
                "attact_type":  "sou",
                "damage_type":  "抓傷",
        ]),
        ([      "action":               "$N往$n的$l狠狠地踢了一腳",
                "attact_type":  "sou",
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N提起拳頭往$n的$l捶去",
                "attact_type":  "sou",
                "damage_type":  "瘀傷",
        ]),
        ([      "action":               "$N對準$n的$l用力揮出一拳",
                "attact_type":  "sou",
                "damage_type":  "瘀傷",
        ]),

});

/* 自定戰鬥訊息 */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}


void kill_ob(object ob)
{
        object *guard;
        int i;
        if(!ob || ob==this_object()) return;
        ::kill_ob(ob);

    guard = all_inventory(environment(this_object()));
        for(i=0;i<sizeof(guard);i++) {
                if( !guard[i]->id("_WUJIAN_") ) continue;
                if( guard[i] == this_object() ) continue;
                if( guard[i]->is_killing(ob->id()) ) continue;

                // guard to kill
                guard[i]->kill_ob(ob);
        }
}

void combat_ai() {
                if( is_busy() ) return;
                if( query_temp("do_attack") ) return;
                message_vision(HIR "腹中首催動「命喪蓋\絕」的殺招，四週氣流狂旋，腹中首臉帶奸笑，欺上身來！！\n" NOR, this_object());
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
        set_name(HIR "腹中首" NOR,({"belly-head spirit","spirit", "_WUJIAN_"}));
        set("gender", "男性");
        set("long",@LONG
出身滅境，在數百年前是與鬼王棺、業途靈合稱「三途判」為禍蒼生
的大魔頭。
LONG
        );

        set("level", 45);
        set("age", 400);
         set("race","tiger");
        set("title", CYN "三途判" NOR);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("sword",100);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (:combat_ai:), 
         }) );        
                 setup();
            set_temp("apply/damage",100);
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
                carry_object(__DIR__"obj/liyuan-claw")->wield();
                if(random(3)==1) carry_object(__DIR__"obj/mercury-lode");

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
                carry_object("/open/world1/eq/bh_leg")->wear();
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

         ob->add("popularity", 2);
         tell_object(ob,HIG "(你獲得 2 點聲望。)\n" NOR);

        ::die();

        return;
}


