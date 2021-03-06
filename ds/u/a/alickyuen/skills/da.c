  //新增 額外增加 bagi force exp -by tmr- 2000/4/2
  //新增 追擊特攻  -by Tmr- 2000/4/3

#include <ansi.h>
  inherit SKILL;
  inherit SSERVER;

  mapping *action = ({
          ([
          "action": "$N一振手中$w，一式"+HIW"『"+NOR"穿雲射日"+HIW"』"+NOR"宛若電馳雷掣似地攻向$n胸中要害",
          "damage":                20,
          "dodge" :                20,
          "parry" :                20,
          "attact_type":  "bar",  
          "damage_type":  "刺傷",
          ]),

          ([
          "action": "只見$N手中$w暴發數丈氣勁，赫然一式"+HIW"『"+NOR"潛龍躍淵"+HIW"』"+NOR"直取$n胸、腹要害",
          "damage":                20,
          "dodge" :                10,
          "parry" :                15,
          "attact_type":  "bar",  
          "damage_type":  "刺傷",
          ]),

          ([
          "action": "只見$N微一凝神，一式"+HIW"『"+NOR"梅花點額"+HIW"』"+NOR"，手中$w挑起數朵碗大槍花，盡罩$n身前數處要害",
          "damage":                25,
          "dodge" :                10,
          "parry" :                20,
          "attact_type":  "bar",  
          "damage_type":  "刺傷",
          ]),

          ([
          "action": "$N陡地將手中$w橫過天際畫了個長弧，一式"+HIW"『"+NOR"長虹繞天"+HIW"』"+NOR"往$n頭頂招呼",
          "damage":                30,
          "dodge" :                10,
          "parry" :                10,
          "attact_type":  "bar",  
          "damage_type":  "劈傷",
          ]),

          ([
            "action": "$N施展一式"+HIW"『"+NOR"回身捕影"+HIW"』"NOR+"，槍勢一變，宛若蛇矢般以奇異的方位直取$n背部要害",
          "damage":                 25,
          "dodge" :                -10,
          "parry" :                -10,
          "attact_type":  "bar",  
          "damage_type":  "刺傷",
          ]),

          ([
          "action": "$N猛喝一聲，狂舞手中$w，登時幻化出數道帶狀氣勁，一式"+HIW"『"+NOR"玉帶繞腰"+HIW"』"NOR+"直攻$n下盤",
          "damage":                30,
          "dodge" :                10,
          "parry" :                10,
          "attact_type":  "bar",  
          "damage_type":  "刺傷",
          ]),

          ([
          "action": "$N一式"+HIW"『"+NOR"魁星舉筆"+HIW"』"+NOR"，手上$w由下往上一挑，勁迅無比地往$n喉嚨刺去",
          "damage":                35,
          "dodge" :                20,
          "parry" :                20,
          "attact_type":  "bar",  
          "damage_type":  "刺傷",
          ]),
  });

  int exert(object me, object target, string arg)
  {
          string msg;
          object weapon,*enemy;
                  
          weapon=me->query_temp("weapon");
          if (!weapon) 
                  return notify_fail("你得拿枝槍才能施展「大槍訣」。\n");
          if(weapon->query("skill_type")!="fork") 
                  return notify_fail("你得拿枝槍才能施展「大槍訣」。\n");

          if(arg=="off" )
          {
                  if( me->query_skill_mapped("fork")!="da-fork")
                          return notify_fail("你並沒有使用「大槍訣」。\n");
                  me->map_skill("fork");
                  me->reset_action();
                  write("技能「大槍訣」已取消。\n");
                  return 1;
          }
          if( me->query_skill_mapped("fork")=="da-fork")
                  return notify_fail("你正在使用「大槍訣」。\n");
          if(me->query_skill("da-fork")<10) 
                  return notify_fail("依你目前的功\力，尚不足施展「大槍訣」。\n");
          if(me->query("ap")<10 || me->query("hp")<10) 
                  return notify_fail("你的身體狀況無法使用「大槍訣」。\n");

          me->map_skill("fork", "da-fork");
          me->reset_action();
          message_vision("\n"HIW"$N手中"+weapon->query("name")+HIW "陡地一震，大槍訣氣勁登時四散而出！！\n"NOR,me);
          me->receive_damage("ap",10);
          me->start_busy(1);
          return 1;
  }

  int valid_learn(object me) {    return 1;       }

  mapping query_action(object me, object weapon)
  {
          int lv,sk,fsk,i,cost,h,power;
           lv =me->query("level");
           sk =me->query_skill("da-fork");
          fsk =me->query_skill("bagi_force");
            h =me->query_skill("horse-steps");

          if(me->is_fighting() && !me->is_busy() ) { 
          
          // 額外增加bagi_force exp
          if(sk > 50 && h > 50 && fsk < 80 && lv > 25 && random(3)==1     )
          {
                  i=me->query_int()+me->query_con();
                  i=i/4+random(i/3);
                  me->improve_skill("bagi_force",i);
          }

          //追擊

          if(me->query_temp("exert-da-fork")!=1
          && sk > 80  && h > 80   && me->query("hp") > 200  
          && me->query("ap") > 200  && random(100) < 20 ) {
          power=sk+h;
            power=power/2+random(power/3);
          me->add_temp("apply/damage",power);
          me->receive_damage("ap",20 );
          me->receive_damage("hp",20 );
          message_vision(HIW"$N馬步一踏，一道大槍氣勁急射而出！！\n" NOR ,me,weapon);

          me->set_temp("exert-da-fork",1); //設定temp 以免多次追擊..
          me->attack();
          me->delete_temp("exert-da-fork");
          me->start_busy(1);
          me->add_temp("apply/damage",-power);
          }

          }

          return action[random(sizeof(action))];
  }

  int practice_skill(object me) { return 1; }

  int improve_limite(object ob)
  {
          int a;
          a=ob->query_int();
          a=70+a;
          return a;
  }

