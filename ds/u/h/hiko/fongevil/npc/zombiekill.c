#include <ansi.h>
inherit SSERVER;

int zombie_heal(object ob);
int zombie_kill(object ob);
void zombie_bite();

mapping *s_action = ({   // 隨機動作
        ([
          "action": "$N往前一步，雙爪左右連出直擊$n$l",
        "damage":                20,
        "attact_type":  "bio",  
        "damage_type":  "抓傷",
        ]),
        ([
          "action": "$N右爪忽然一晃，聚力擊向$n$l",
        "damage":                25,
        "attact_type":  "bio",  
        "damage_type":  "擊傷",
        ]),
        ([
        "action": "$N陡地雙爪向著$n的$l要害同時連擊",
        "damage":                25,
        "attact_type":  "bio",  
        "damage_type":  "抓傷",
        ]),
        ([
          "action": "$N雙臂一震，右爪刺出，左爪陡地由側邊伸出擊向$n$l",
        "damage":                40,
        "attact_type":  "bio",  
        "damage_type":  "刺傷",
        ]),

        ([
          "action": "$N搖搖晃晃張嘴便往$n的$l咬去，使$n血流不止",
        "damage":                40,
        "attact_type":  "bio",  
        "damage_type":  "咬傷",
        ]),

        ([
   "action": "$N面目猙獰，忽然向$n的$l抓了幾下！",
        "damage":                25,
        "attact_type":  "bio",  
        "damage_type":  "抓傷",
        ]),
});

int zombie_heal(object ob)  // 補血
{
        if( ob->is_busy() )     return 1;
         if( ob->query("hp") > ob->query("max_hp")/2 ) return 1;
        message_vision( CYN"\n$N"+CYN+"嘶吼一聲，忽然有陣陣陰氣傳入...\n" NOR,ob);
        ob->receive_heal("hp",ob->query("max_hp")/15 );
        ob->start_busy(1);
        return 1;
}

int zombie_kill(object ob)  // 殭屍王特攻
{               object target = offensive_target(ob);  // 敵人
        if(ob->is_busy() ) return 1;
        switch(random(4) ) {
        case 0:
                message_vision(HIY "\n""        $N忽然雙爪連出，連續擊出兩下...\n" NOR,ob);
                ob->attack();
                ob->attack();
        break;
        case 1:
    message_vision(HIY "\n""         $N忽然一陣猛攻，令你只得停下身形防備...\n" NOR,ob);
                target->start_busy(1);
        break;
        case 2:
                message_vision(HIG "\n      $N吸了一口陰氣，猛力擊出一擊...\n" NOR,ob);
                ob->start_busy(1);
                target->start_busy(1);                           target->receive_damage("hp",180+random(ob->query_str()));   
                COMBAT_D->report_status(target);        
        break;
        }
        return 1;
}

void zombie_bite()
{
        object me,target;
        me=this_player();
        target = offensive_target(me);  // 敵人
        if(!me || !target) return;
        if(me->is_busy()) return;
        message_vision(HIR"\n$N一聲大吼，雙爪「唰∼」的刺中$n" NOR,me,target);
        target->receive_damage("hp",50+random(me->query_str()),target);
        COMBAT_D->report_status(target);

}










