#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit NEEDLE;

void create()
{
          set_name(MAG"十方靈動"NOR,({"viper needle","needle"}) );
          set("long","一根紫色的針，形狀像是一條蛇，當你注意看時，好像會如有生命般
緩緩遊動，針上有隱隱約約的看到一層紫氣。\n");
        set_weight(2300);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
              set("value",40000);
              set("limit_level",30);
              set("material", "blacksteel");
        }
        set("wield_msg","$N握住了$n，手上紫氣隱隱顯現。\n");
         init_needle(40);
        set("soul_times",0);
        set("soul_levels",0);
          set("replica_ob", __DIR__"needle.c");
        set("weapon_prop/str", -4);
        set("weapon_prop/tec", 1);
        set("weapon_prop/int", 3);
        setup();        
}


void soul_lv(int lv)
{
 mixed level = ({"空無一物","漸入佳境","鋒芒畢露","爐火純青","深不可測"
                 ,"出類拔萃","登峰造極","毀天滅地",});
 int times,levels;
 times = this_object()->query("soul_times");
 levels = this_object()->query("soul_levels");
 times = times + lv;
 if (times >= (levels+1)*15 && levels < 15)
 {
  levels = levels +1;
  times = 0;
  write(MAG"十方靈動突然泛起一道紫光••\n"NOR); 
    if(levels<=15) set("long","一把紫色的針，形狀像是一條蛇，當你注意看時，好像會如有生\n"+
                            "命般緩緩遊動，匕上有隱隱約約的看到一層紫氣。\n"+
                            query("name")+"等級："+level[levels/2]+"\n");
  set("soul_levels",levels);
  this_object()->unequip();
  init_needle(40+levels*2);
  this_object()->wield();
  set("backstab_bonus",10+levels*3);
 }
 set("soul_times",times);
 return;
}
 
void attack(object me,object victim)
{ 
  int lv;
  int attack_times;
  object ob = this_object();      
        ::attack(); 
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;

       if (((!victim) || (victim->query("hp") < 0)))  //找不到攻擊對象(可能打死mob在query到hp<0前離開)
       {                                               //或是打死mob並在當格query到mob hp<0
       if(victim) lv=victim->query("level");
       else lv=1;
       message_vision("$N"HIC"手中的"NOR+MAG"十方靈動"NOR+HIC"突然幻化成一條巨蛇，將$n的魂魄吸收。\n"NOR,me,victim);
       soul_lv(lv * 2);
       }

        if(random(5)) return; // 1/5 的機率特攻
        message_vision("$N"MAG"手中的十方靈動如蛇一般向$n快攻數招！\n"NOR,me,victim);
        attack_times=me->query_dex()/30;
        switch( attack_times ) {
         case 0: 
          message_vision(HIY"\n無耐$N因殺氣不足使得攻擊無法連續下去••\n"NOR,me,victim);
          me->start_busy(1);
          break;       
         case 1:
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);   
          break;
         case 2:
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);  
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);   
          break;
         default:
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);  
          COMBAT_D->do_attack(me, victim, this_object(), 4);
          COMBAT_D->report_statue(victim);    
          COMBAT_D->do_attack(me, victim, this_object(), 3);
          COMBAT_D->report_statue(victim);   
          break;        
        }
        return; 
} 

