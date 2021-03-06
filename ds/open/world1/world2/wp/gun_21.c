#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("ＣＫ來福槍",({"ck rifle","rifle"}));
set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",@LONG
這是一把ＣＫ重機生產的長距離射擊(shoot)武器，可以裝填(reload)
八發三厘米子彈。
LONG);
		set("unit", "把");
		set("rigidity",500);	//新增: 硬度
		set("material","iron");
//
// 條件可以是 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
		set("limit_int",8);
		set("limit_dex",7);
		set("limit_str",2);
        }

	set("wield_msg","$N拿起一把$n，並將$n的保險裝置解開。\n");
	set("unwield_msg", "$N將手中的$n保險裝置關閉，掛在肩上。\n");

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	命中率
//  weapon_prop/parry	招架率
//
	set("bullet_type","small");	//可用子彈種類
	set("max_load",8);		//最大裝填量
	init_gun(21); 	// 肉搏傷害力=set("weapon_prop/damage", 14);
	setup();
	set("value",3180);
}
int do_shoot(object me,object target)
{
	string msg;
	int damage;
	
	  if(!me || !target) return 0;
	  this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
	  msg=HIW+"$N"+HIW+"突然用"+this_object()->name()+HIW+"對準$n"+HIW+"射出了一";
	  if(stringp(this_object()->query_temp("bullet/unit"))) msg+=this_object()->query_temp("bullet/unit");
		else msg+="發";
	  if(stringp(this_object()->query_temp("bullet/name"))) msg+=this_object()->query_temp("bullet/name")+"﹗\n"+NOR;
		else msg+="子彈﹗\n"+NOR;
	   if(!me->is_fighting(target)) me->kill_ob(target);
	  message_vision(msg,me,target);
	  me->start_busy(1);
	  me->improve_skill(this_object()->query("skill_type"),1+me->query_int()/3+random(me->query_int()));
	  //check if target can dodge
	  if(COMBAT_D->attack_factor(me,this_object()->query("skill_type"))+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 300 )
	  {
	   message_vision("$N迅速的往旁邊翻了兩個觔斗, 漂亮的閃過了$n的射擊。\n"+NOR,target,me);
	   target->improve_skill("dodge",1+random(target->query_int()/6));
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   return 1;
	  }
	
	  damage=this_object()->query_temp("bullet/damage");
	  damage= 80+damage*3+random(100);
	  damage-=target->query_armor()/4-random(target->query_armor()/3);
	  if(damage<5) damage=random(10);
	  if(damage<1)
	  {
	   message_vision(HIW+"$N"+HIW+"把"+this_object()->query_temp("bullet/name")+HIW+"給彈開了。\n"+NOR,target);
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   return 1;
	  }
	  message_vision("$N楞了一楞, 正想閃避時卻已經被"HIW"射中"NOR", "HIR"受傷不輕"NOR"。\n",target,me);
	  target->receive_damage("hp",damage,me);
	  if(random(10) == 1 ) target->receive_wound("random",random(4)+1,me);
	  target->add_busy(1);
	  COMBAT_D->report_status(target);
	  if(!target->is_fighting(me)) target->kill_ob(me);
	  return 1;
}

