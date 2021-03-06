#include <weapon.h>
#include <ansi.h>
#include <skill.h>
inherit SSERVER;
inherit HAMMER;
void create()
{
	set_name("小形木製算盤", ({ "small wood abacus","abacus" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("long", "這是一個計算物品數量或價錢時常常會用到的算盤，\n"
                            "不過你卻發現這個算盤的算珠似乎可以彈射(throw)出去。\n");
		set("value", 500);
		set("material", "wood");
		set("capacity",115);
		set("can_load","small");
		set("can_shoot",1);
		set("need_skill",10);
		set("is_abacus",1);
        }
    set_temp("abacus/damage",10);
    set_temp("abacus/unit","顆");
    set_temp("abacus/name","小算珠");
    set_temp("abacus/type","small");
    set_temp("loaded",115);
    init_hammer(10);
    setup();
}
void init()
{
	add_action("do_throw","throw");
}
int do_throw(string arg,object me)
{
	object target,weapon;
	string msg,damagemsg;
	int damage;
   	me=this_player();
        weapon=me->query_temp("weapon");
	if(!weapon) return 0;
	if(!weapon->query("can_shoot"))
		return notify_fail("你目前使用的算盤不能彈射算珠。\n");
	if(this_object()->query_temp("loaded") < 1 )
		return notify_fail("你的算盤已經空了。\n");
	if( me->is_busy() )
		return notify_fail("( 你上一個動作還沒有完成﹐不能彈射算珠。)\n");
	if( me->query_skill("finger") < 3 ) // 這邊控制的是底限
		return notify_fail("憑你的指法還不能彈射算珠..\n");
	if( me->query_skill("finger") < (this_object()->query("need_skill")/3)+random((this_object()->query("need_skill")*2/3)) ) //控制難度
	{
		this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
		me->receive_damage("hp",this_object()->query_temp("abacus/damage"));
		return notify_fail("你的指法不精熟, 不小心彈到了自己.\n");
	}
	if(!arg) target = offensive_target(me);
	else target = present(arg, environment(me));
	if( !target ) return notify_fail("[shoot] error: 找不到目標。\n");
	if(	!target->is_character()
	||	target->is_corpse()
	||	target->is_ghost())
	{
		return notify_fail("[shoot] error: 只能對生物射擊。\n");
	}
	if( me->is_ghost() ) return notify_fail("你現在還是鬼魂吧。\n");
	if(userp(me) && userp(target))	//攻擊的一定要設定
	{
	  if(me->query("level") < 5 ) return notify_fail("你目前的等級不可以攻擊玩家﹗\n");
	  if(target->query("level") < 5 ) return notify_fail("你不可以攻擊如此低等級的玩家﹗\n");
	  if(me->query("level") > target->query("level") + 5 ) return notify_fail("你不可以攻擊等級相差太多的玩家﹗\n");
	  if(me->query("level") < target->query("level") - 5 ) return notify_fail("你不可以攻擊等級相差太多的玩家﹗\n");
	}
	  if(!me || !target) return 0;
	  this_object()->set_temp("loaded",this_object()->query_temp("loaded")-1);
	  msg="$N指勁一抖, 力貫"+this_object()->name()+"之上, 瞬間向$n彈出一";
	  if(stringp(this_object()->query_temp("abacus/unit"))) msg+=this_object()->query_temp("abacus/unit");
		else msg+="顆";
	  if(stringp(this_object()->query_temp("abacus/name"))) msg+=this_object()->query_temp("abacus/name")+"!\n"+NOR;
		else msg+="算珠!\n"+NOR;
	  if(!me->is_fighting(target)) me->kill_ob(target);
	  message_vision(msg,me,target);
	  me->start_busy(1);
	  if(!target->is_fighting(me)) target->kill_ob(me);
	  me->improve_skill("finger",1+random(me->query_int()/6));
	  //check if target can dodge
	  if(COMBAT_D->attack_factor(me,"finger")+COMBAT_D->dodge_factor(target,"dodge")+random(401) < 150 )
	  {
	   message_vision("$N轉身一閃，躲開了飛射而來的算珠。\n",target,me);
	   target->improve_skill("dodge",1+random(target->query_int()/6));
	   return 1;
	  }
	  damage=this_object()->query_temp("abacus/damage")+this_object()->query("weapon_prop/damage");
	  damage= damage*2/3+random(damage/3)+(me->query_skill("finger")/3);
	  damage-=target->query_armor();
	  damage = COMBAT_D->Merits_damage(me,target,damage,"tec");
	  if(damage<1)
	  {
	   message_vision("$N大喝一聲, 居然把"+this_object()->query_temp("abacus/name")+"硬生生的給撥開了。\n",target);
	   target->improve_skill("parry",2+random(target->query_int()/5));
	   return 1;
	  }
	  if(damage < 10) damagemsg = "$N輕微的傷害。";
	  else if(damage < 40) damagemsg = "$N一處傷害。";
	  else if(damage < 80) damagemsg = "$N一處嚴重的擊傷。";
	  else if(damage < 150) damagemsg = "$N一處十分嚴重的擊傷！";
	  else if(damage < 250) damagemsg = "$N一處非常嚴重的重大傷害！";
	  else if(damage < 350) damagemsg = "$N受傷處皮肉爆開，鮮血狂噴！！";
	  else damagemsg = "$N的受傷處穿了個透體而過血肉模糊的大洞！！";
	  message_vision("$N閃避不及，被"+this_object()->query_temp("abacus/name")+"射中，造成"+damagemsg+"\n",target,me);
	  target->receive_damage("hp",damage,me);
	  if(random(10) == 1 ) target->receive_wound("random",random(damage/20)+1,me);
	  COMBAT_D->report_status(target);
	  return 1;

}