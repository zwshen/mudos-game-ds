#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
inherit SWORD;
void create()
{      
	set_name(HIB"終結之劍"NOR,({"final sword","sword"}) );
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",HIG"這是一把終結聖劍。\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("limit_str",10);
        set("limit_con",10);
        set("limit_dex",10);
        set("limit_int",10);
        set("weapon_prop/hit",100);
        set("material", "blacksteel");
        set("wield_msg",HIR"$N臨空一指，天上飛來一把聖劍，$N手握$n。\n"NOR);
        set("unwield_msg", RED"$N將手中的$n往天上一拋，$n無影無蹤了。\n");
        init_sword(1000000);
        setup();
        }
}
void attack(object me,object victim)
{
	int damage,hp,maxhp,mp;

  me=this_player();
  hp=me->query("hp");
  maxhp=me->query("max_hp");
  mp=me->query("mp");
 if ( hp < maxhp/2 )
 { 
   damage=100000+random(10) *(hp+mp);
  message_vision(HIR" 終結之劍吸收了所有力量，砍出超級一擊！！！
  造成$N"+damage+"點的傷害！！！！\n"NOR,victim); 
  victim->receive_damage("hp", damage, me );
 me->set("hp",1);
 me->set("mp",0);
 return;    
 }
}
void init()
{
  add_action("do_berserk","berserk");
}
int do_berserk(string arg)
{
 object me, target;

 int skill, cost;
 
 me=this_player();
 if(!me) return 0;
 if(me->start_busy()) return notify_fail("你動作還沒完成..\n");
 if(me->query_temp("berserk")) return notify_fail("你不能連續施展禁咒.\n");
 if(!me->is_fighting())
        return notify_fail("這個技能只能在戰鬥時使用。\n");
 if(arg)
 {
  target=present(arg, environment(me));
  if(!target) return notify_fail("要對誰施展禁咒??\n");
  if(!me->is_fighting(target)) return notify_fail("這個技能只能對你目前的敵人使用。\n");
 }
 else target = offensive_target(me);   
 if(!target) return notify_fail("這個技能只能對你目前的敵人使用。\n");
 skill=me->query_skill("berserk",1);
 cost = 25;
 if(me->query("mp") < cost) return notify_fail("你目前的體力狀況無法施展禁咒\n");
 message_vision(HIR"\n$N手上的終結之劍頌著古代魔法的禁咒！...\n\n"NOR,me);
 skill/=8;
 me->set_temp("berserk",1);
 me->start_busy(2);
 me->add("mp",-cost);
 call_out("do_crazy",4,me,target,skill);
 call_out("do_clean",8,me);
 return 1;
}
int do_crazy(object me,object target,int times)
{
  int i;
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("berserk");
    return notify_fail("目標似乎脫離了你的攻擊範圍..\n");
  }
  message_vision(HIY"\n∼∼隆隆∼∼天上突然向$N射出一束光線！！\n\n",me);
  for(i=0;i < times ;i++)
  COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_BERSERK); 
  COMBAT_D->report_status(target);   
  me->improve_skill("berserk",1+random(me->query_int()/10));
  return 1;
}

int do_clean(object me)
{
 if(!me) return 0;
 me->delete_temp("berserk");
 return 1;
}

int query_autoload() { return 1; }

