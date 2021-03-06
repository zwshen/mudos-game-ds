#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({
  ([
        "action": "$N眼神一變，手腕一轉，將$w拖在地板上衝向$n，霎時使出一招"HIC"「疾滅斬天」"NOR"斬向$n",
        "damage":       30,  //這個是傷害強化的百分比 , 不是傷害點數
        "parry":        -10,
        "attact_type":  "bar",  // 設定技能的攻擊種類 // 生物(bio) 獸性(bar) 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "斬傷", 
  ]),
  ([
        "action": "$N手指按著刀柄，腳尖一蹬，快速的奔到$n的身旁，拔刀迴斬，一式"HIG"「旋龍破」"NOR"狠狠的落在$n",
        "damage":       27,
        "parry":        -2,
        "attack_type":  "bar",
        "damage_type":  "斬傷",
  ]),
  ([
        "action": "氣定神閒,內勁頓時湧了上來，只見$w冒出了一道熊熊烈火,一式"HIR"「赤焰閃」"NOR"毫不留情的帶著烈火燃燒的聲響燒向$n",
        "damage":       35,
        "parry":        -15,
        "attack_type":  "bar",
        "damage_type":  "燒傷",
  ]),
  ([
        "action": "$N把$w刀往上一丟順勢跳了上去，氣勁一運，使出一式"HIB"「破空一線」"NOR"人和刀似乎化為一體,像一條閃電般向$n穿去",
        "damage":       37,
        "parry":       -20,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
  ])
});

int cast_skill(object me,string a, object target, string arg)
{
        int sk = me->query_skill("taingin-blade"),
            
target_armor, me_damage, target_dodge, me_dex, sum_damage, penuma_damage, g,damage;

        object weapon, *attack_targets;
        
        weapon = me->query_temp("weapon");
        
       if( arg=="off" )
        {
               if( me->query_skill_mapped("blade")!="taingin-blade" ) return notify_fail("你並沒有在施展天劍疾刀流！\n");
                me->reset_action();
                write("你將刀向旁一甩，散掉了「天劍疾刀流刀法」之劍氣。\n");
                return 1;
        }

        if( me->query("ap") < 30 )
                return notify_fail("你身體的狀況不能再施展天劍疾刀流。\n");

          if( !weapon ) return notify_fail("你不拿把刀要怎麼施展「天劍疾刀流」？\n");

          if( weapon->query("skill_type")!="blade" )
                return notify_fail("你不拿把刀要怎麼施展「天劍疾刀流」？\n");

        if( arg == "?" || arg == "help" )
        {
                tell_object(me, HIC"「"HIC"天劍疾刀流"HIC"」的絕招有 一字狂風斬(one-chop) 霸王櫻花斬(overlord-chop)。\n"NOR);
                return 1;
        }

    if( me->query_skill_mapped("blade") == "taingin-blade" )
        {
                if( !target ) target = offensive_target(me);
                if( !target ) return notify_fail("你還在施展天劍疾刀流！\n");
                if( !me->can_fight(target) ) return me->can_fight(target);

                target_armor = target->query_armor();
                target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                me_dex = me->query_dex() * 3;
                me_damage = me_damage + random(me_damage/4);
                sum_damage = me_damage - target_armor/2 - random(target_armor/2);
                // qc section
                if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
                // end of qc section
                if( !arg || arg == "?" )
                {
                        tell_object(me, HIC"「"HIC"天劍疾刀流"HIC"」的絕招有 一字狂風斬(one-chop) 霸王櫻花斬(overlord-chop)。\n"NOR);
                        return 1;
                }

  if( arg == "one-chop" )
                {
                        if( !me->is_fighting(target) ) me->kill_ob(target);
                        if( !target->is_fighting(me) ) target->kill_ob(me);
                       if( me->is_busy() ) return notify_fail("你正在忙！\n");
                        if( me->query_skill("taingin-blade") < 40 )
                                return notify_fail("你的天劍疾刀流還不夠純熟！\n");
                        message_vision(HIG"\n$N把" + weapon->name() + "用力的插入地板，突然狂風大作，你身旁冒出了一道龍捲風包住了你向$n鑽去
                  你順勢拔起了" + weapon->name() + "怒吼一聲"HIY"「∼一字狂風斬∼」"NOR"。\n\n", me, target);
                        if( random(me_dex) > random(target_dodge)
                        && sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                        {
                                target->receive_damage("ap", sum_damage/25, me);
                                target->receive_damage("hp", sum_damage, me);
                                target->start_busy(random(3));
                                message_vision(HIR"$n一個不小心，被$N用"HIY"「∼一字狂風斬∼」"NOR"鑽進了胸口，結果胸口鮮血狂噴！！"NOR, me, target);
                                // QC
                                if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                                // End QC
                                me->improve_skill("tainginr-blade", random(me->query_int()/5) + 5);
                                me->improve_skill("blade", random(me->query_int()/6) + 5 );
                                me->add_busy(2); 
                        }
                        else
                        {
                                message_vision(HIY"$n慌慌張張的閃了開，但也嚇的屁滾尿流。"NOR, me, target);
                                target->imporve_skill("dodge", 5);
 sum_damage = 0;
                                me->add_busy(2); 
                        }
                     
               }

                if( arg == "overlord-chop" )
             {
        if( !me->is_fighting(target) ) me->kill_ob(target);
                if( !target->is_fighting(me) ) target->kill_ob(me);
                if (me->query_skill("taingin-blade") < 70)
                if( me->is_busy() ) return notify_fail("你正在忙！\n");
                return notify_fail("你駕馭天劍疾刀流的能力還沒到這麼強的地步。\n");
              if(me->query("ap")<50) 
                return notify_fail("你目前的內勁不足，無法使出奧義。\n");

                //攻擊性的要特別注意要加下面兩行.
           if(!me->can_fight(target)) return me->can_fight(target);
           if(!me->is_fighting(target) ) return notify_fail("你並沒有在戰鬥中。\n");
                message_vision(HIW"$N兩腳一踏..突然飛了起來.......越來越高..越來越高....

               地面上事物皆一覽無遺...$N閉上了雙眼..身體突然往下疾速下墜..\n\n"NOR,me);
                me->receive_damage("ap",15+random(16));
            me->start_busy(3);
                call_out("superpower",1,me,target,1,damage);
                return 1;
        }
        }
}
void superpower(object me,object target,int z,int damage)
 {
      string msg;
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
      if(!me->is_fighting(target)) me->kill_ob(target);

       z=me->query_skill("taingin-blade");

       msg = "$N突然睜開雙眼，怒吼一聲"+HIC+"【奧義】"+NOR+"∼"+HIY+"【"+NOR+"霸王櫻花斬"+HIY+"】"+NOR+"∼，\n";
       msg += "驚天動地，鬼哭神號，刀光閃爍，$w重重的落在$得天靈蓋上.\n";
     message_vision(msg, me, target);

       if( z/3 + random(z) > random(target->query_skill("dodge")) )
       {
         damage = me->query_skill("blade") + random(me->query("str")) - target->query_armor()/2 - random(target->query_armor()/2) - (target->query("con"));
         if(damage>405) damage=405+((damage-405)/5);
         if(damage<40) damage=40+random(8);

         message_vision(HIR "\n結果$n身上從頭到腳被劈出一道恐怖駭人的傷痕，狂噴了好多血。\n" NOR,me,target);

            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,target,damage,"bar");

            target->receive_damage("hp",damage,me);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                 tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                 tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(targe
t);
       }
else {
            message_vision(HIW "\n$n驚慌失措，大聲尖叫，躲過了這招奧義。\n" NOR,me,target);
}

}

        if( !me->skill_active( "taingin-blade",(: call_other, __FILE__, "delay_0", me :), 6) )
                return notify_fail("你結束天劍疾刀流的動作還沒完成！\n");
          
        message_vision(HIY"$N拿起手中"+weapon->query("name")"，，施展出天劍疾刀流！\n"NOR,me);
        me->map_skill("blade", "taingin-blade");
        me->receive_damage("ap", 10);
        me->reset_action();
        me->start_busy(1);
        return 1;
}

void delay_0(object me)
{
        object me_weapon;
        int sk = me->query_skill("taingin-blade");
 if( !me ) return;

        me_weapon=me->query_temp( "weapon" );

        if( !me_weapon || me_weapon->query("skill_type") != "blade" )
        {
                me->map_skill("blade");

                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("blade")!="taingin-blade" ) return;

        if( me->query("ap") < 20 )
        {
                me->map_skill("blade");
                me->reset_action();
                tell_object(me, "你的體力已不能繼續施展「天劍疾刀流」了！\n");
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap", 10);
me->skill_active( "taingin-blade",(: call_other, __FILE__, "delay_0", me :), 6);



}

}
int valid_learn(object me)
{
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return 1;
}
int improve_limite(object ob)
{
        return 100;
}
