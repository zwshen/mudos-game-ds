#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(GRN"八方銅劍"NOR, ({ "ba-fang longsword","sword" }) );
        set_weight(12000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("material","crimsonsteel");
        set("limit_str",25);  
        set("limit_level",25); 
        set("long","這口劍皮賄華美，柄上嵌著松綠石，鑲金絲，劍柄與劍身中的『彪』\n"
                   "，雖似黃金鑄成，都作玄銅額色。\n");
        set("wield_msg",HIG"$N緩緩的從古樸的劍鞘中抽出$n"HIG"，一陣綠光爍爍。\n"NOR);

        set("unwield_msg", "$N將手中的$n輕輕插入劍鞘。\n");
        set("value",5000);
        } 
        set("weapon_prop/str", 1);
        set("weapon_prop/dex", 1);
        set_temp("sec_sword",1);
        init_sword(35, SECONDARY); 
        setup();
}

void attack(object me,object victim)
{
        object wp,ob = this_object();
        int x = me->query_skill("sword")/20+me->query_skill("force")/40,
           damage = x*50 + me->query_temp("apply/damage"),
           i;
        ::attack();
        if( !me->query_temp("secondary_weapon") ) return;
        wp=me->query_temp("secondary_weapon");
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return; 
        if(!wp->query_temp("sec_sword")) return;
      switch( random(10) ){
       case 0:
        message_vision(
        "$N"HIC"泛起青湛湛的異芒，畫過超乎人間美態，具乎天地至理的動人線條，空中的灰塵似鐵\n"
        "遇磁石般被吸引，水流般竄往$N"HIC"的鋒尖，剎那間累凝而成一球煙霧，劍鋒化為一點青光\n"
        "，似若雲霞繚繞裡的不滅星光，流星般往$n"HIC"雙目間的位置奔來。\n"NOR,ob,victim);    
        COMBAT_D->do_attack(me, victim, this_object(), random(5));
        COMBAT_D->report_statue(victim);
        COMBAT_D->do_attack(me, victim, this_object(), random(5));
        COMBAT_D->report_statue(victim);
        COMBAT_D->do_attack(me, victim, this_object(), random(5));
        COMBAT_D->report_statue(victim);
       break;
       case 1:
        message_vision( 
        HIG"\n八方銅劍倏地劍光大盛，$N在氣機牽引下，手上青芒暴漲，越過間距橫空而來，\n"
           "八方銅劍將一個一個由小至大的氣環串套劍身，隨著八方銅劍前推，如龍吐珠的把\n"
           "從小至大的氣環往$n"HIG"送來！\n"NOR,me,victim);
         if( victim->is_busy() || me->query_temp("apply/hit") > victim->query_temp("apply/dodge")
          && me->query("ap") > x ){
            message_vision("$N被"+chinese_number(x)+"個氣環擊中，傷勢十分嚴重•",victim);
            if(victim->query_temp("apply/show_damage") || victim->query_temp("show_damage") )
            tell_object(victim,HIR"("+damage+")\n"NOR);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIR"("+damage+")\n"NOR);
            victim->receive_damage("hp",damage);
         } else if( me->query_skill("sword")+me->query_skill("force")
                  > victim->query_skill("parry")+victim->query_skill("force") ) {
            i = (victim->query_skill("force") - me->query("force"))/10 + 1;
        message_vision("$N用自身深厚的內功\底子，化解了"+chinese_number(i)+"個氣環•\n",victim);
        message_vision("但剩下的"+chinese_number(x-i)+"還是擊中了$N，仍然造成不小的傷害•",victim);
        if(victim->query_temp("apply/show_damage") || victim->query_temp("show_damage") )
        tell_object(victim,HIR"("+damage/i+")\n"NOR);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIR"("+damage/i+")\n"NOR);
        victim->receive_damage("hp",damage/i);
         } else {
            message_vision("$N驚險的躲掉了攻擊•\n",victim);
         }
         me->receive_damage("ap",x);
       break;
      }       
      return;
}

