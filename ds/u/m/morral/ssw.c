#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void running_fire(object me,object target,int z,int damage);

mapping *action = ({
	([
	"action": "$N凝神一定，將手中的劍忽地舞成劍花，\n在趁$n不注意時，一舉使出「風嘯雲龍」，往$n胸口刺去。",
	"damage":                30,
	"dodge" :                15,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$N大喝一聲，迅速使出「內殮自省」，劍尖往$n手上的五大要穴而去。",
	"damage":                20,
	"dodge" :                -5,
        "damage_type":  "刮傷", 
        ]),
	([
	"action": "$N集中精神，凝神歸氣，把在六大脈中的真氣迅速收回檀中，\n一霎那間，$N把劍使出如繩索一般往$n身上狂掃而去。",
	"damage":                25,
	"dodge" :                10,
        "damage_type":  "鞭傷", 
        ]),
	([
	"action": "$N內心一股衝動，把劍使出一招「小亂劍」，\n將劍身彎成像圓環一般往$n的頭部砸去。",
	"damage":                15,
	"dodge" :                -3,
        "damage_type":  "創傷", 
        ]),
	([
	"action": "$N從腰際拿了一袋酒袋，喝了一喝，似乎醉了一般，\n一不小心使出「酒謎醉人」，便如酒拳一般把$n用的不知該如何是好。",
	"damage":                20,
	"dodge" :                -15,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$n一不小心滑了一跤，$N眼見有利可得，馬上把手中的劍往$n身上刺去。",
	"damage":                23,
	"dodge" :                13,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$N使出一招平平無奇的中宮劍往$n身上要穴而去，\n不料在途中突轉變為「曲龍幽行」，把劍硬生生的轉了個彎，刺向$n的兩眼。",
	"damage":                18,
	"dodge" :                5,
        "damage_type":  "刺傷", 
        ]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage;
	string msg;
	object weapon;
	mapping type;
	
	weapon=me->query_temp("weapon");
	
	if( arg=="off" )
	{
		if( me->query_skill_mapped("sword")!="sorgi_sword" )
			return notify_fail("你並沒有使用【索極劍法】。\n");
		me->map_skill("sword");
		me->reset_action();
		write("技能中的「索極劍法」已停止使用。\n");
		return 1;
	}

	if( !weapon)
		return notify_fail("【索極劍法】的使用一定要有劍。\n");

	if( weapon->query("skill_type")!="sword" )
		return notify_fail("如果要使用索極劍法，則必須裝備劍類武器。\n");

	if( me->query_skill("sword") < 10 )
		return notify_fail("你拿起劍來想耍一耍劍招，結果因為還劍法還不純熟而打到了自己！！！\n");

	if( me->query("mp") < 20 )
		return notify_fail("你的體力還不足以使用索極劍法。\n");

	if( me->query_skill_mapped("sword")=="sorgi_sword" ) 
	{
		if( !target ) target = offensive_target(me);
		if( !target ) return notify_fail("你還在施展【索極劍法】。\n");
		if( !me->can_fight(target) ) return me->can_fight(target);
		if( !me->is_fighting(target)) me->kill_ob(target);
		if( !target->is_fighting(me)) target->kill_ob(me);
		c = target->query_armor();

		if( me->query_skill("sorgi_sword") > random(300) )  
		{
			msg = HIY"\n$N使出內力把自身隱藏暴發的力量，使出一招「無我亦無人」從$n的上方巧妙的往$n的頸部而去！！\n"NOR ;
			damage = me->query_skill("sorgi_sword") + me->query_damage() *1.5;
			damage -= random( target->query_armor() );
	 		if( damage < 40 ) damage = 40 + random(me->query_str());

	 		me->start_busy(2);

			if(random(me->query_skill("sorgi_sword")) > 30 )
			{
				msg += HIM "結果$n的頸部被$N狠狠擊中，登時頸部大動脈倏地噴出大量鮮血﹗\n" NOR;
				target->start_busy(5);
				target->receive_damage("hp",damage,me);
				COMBAT_D->report_status(target);
			        me->improve_skill("sorgi_sword",1+me->query_int()/10);
			        me->improve_skill("sword",1+me->query_int()/10);
			}
			else
			{
				msg += HIY"不料$n竟對$N的出招不理不采，繼續出招，結果沒有照成任何的傷害。\n" NOR;
			}

			message_vision(msg, me, target);
			me->receive_damage("mp",25);
			return 1;
		}
		else
		{
			damage = me->query_skill("sorgi_sword") + me->query_damage();
			damage -= random( target->query_armor() );
	 		if( damage < 30 ) damage=25+random(15);
			i=(me->query_skill("sorgi_sword"))+(me->query_skill("fogseven")/2);
			if ( i > 50 )i = 2;
			if ( i < 51 )i = 1;
			if ( i == 2 )
			{
				me->start_busy(4);
				call_out("running_fire",0,me,target,2,damage);
			}
			if ( i == 1 )
			{
				me->start_busy(3);
				call_out("running_fire",0,me,target,1,damage);
			}
			return 1;
		}
        }

	message_vision("\n"HIC"$N大喝一聲，把全身的真氣鑽往胸口壇中而去！\n"NOR,me);
	me->map_skill("sword", "sorgi_sword");
	me->reset_action();
	me->receive_damage("mp", 7);
	me->receive_damage("mp", 7);
	me->start_busy(2);
	call_out("delay",8,me);
	return 1;

}

void delay(object me)
{
	object weapon;
	if( !me ) return;
	weapon=me->query_temp( "weapon" );

	if( !weapon )
	{
	 	me->map_skill("sword");
		me->reset_action();
		remove_call_out("delay");
		return;
	}

	if( me->query_skill_mapped("sword")!="sorgi_sword" )
	{
		remove_call_out("delay");
		return;
	}

	if( me->query("mp")<10 )
	{
	 	me->map_skill("sword");
		me->reset_action();
		message_vision("\n"HIW"$N的體力不夠無法繼續施展索極劍法。\n"NOR,me);
		remove_call_out("delay");
		return ;
	}

	if( me->is_fighting() ) me->receive_damage("mp",7);

	call_out("delay",8,me);
}

void running_fire(object me,object target,int z,int damage)
{
	string a="$N凝神一定，將手中的劍忽地舞成劍花，\n在趁$n不注意時，一舉使出「風嘯雲龍」，往$n胸口刺去。\n",
	       b="$N大喝一聲，迅速使出「內殮自省」，劍尖往$n手上的五大要穴而去。\n",
	       c="$N集中精神，凝神歸氣，把在六大脈中的真氣迅速收回檀中，\n一霎那間，$N把劍使出如繩索一般往$n身上狂掃而去。\n",
	       d="$N從腰際拿了一袋酒袋，喝了一喝，似乎醉了一般，\n一不小心使出「酒謎醉人」，便如酒拳一般把$n用的不知該如何是好。\n",
	       e="$N使出一招平平無奇的中宮劍往$n身上要穴而去，\n不料在途中突轉變為「曲龍幽行」，把劍硬生生的轉了個彎，刺向$n的兩眼。\n",
	       msg;

	if ( z==1 ) 
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_str())*2) )
		{
			a += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(a, me, target);
                        COMBAT_D->report_status(target);
                	target->receive_damage("hp", random(damage) , me );
			b += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(b, me, target);
			COMBAT_D->report_status(target);
                	target->receive_damage("hp", random(damage) , me );
			c += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(c, me, target);
			COMBAT_D->report_status(target);
                	target->receive_damage("hp", random(damage) , me );
		        me->improve_skill("sorgi_sword",1+me->query_int()/8);
		        me->improve_skill("sword",1+me->query_int()/7);
		}
		else
		{
			msg = "$N想使出索極劍中的連發絕技，可是卻被$n給看破了。\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
		return;
	}

	if ( z==2 )
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_str())*2) )
		{
			a += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(a, me, target);
			COMBAT_D->report_status(target);
                	target->receive_damage("hp", random(damage) , me );
			b += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(b, me, target);
			COMBAT_D->report_status(target);
                	target->receive_damage("hp", random(damage) , me );
			c += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(c, me, target);
			COMBAT_D->report_status(target);
                	target->receive_damage("hp", random(damage) , me );
			d += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(d, me, target);
			COMBAT_D->report_status(target);
                	target->receive_damage("hp", random(damage) , me );
			e += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(e, me, target);
			COMBAT_D->report_status(target);
                	target->receive_damage("hp", random(damage) , me );
		        me->improve_skill("sorgi_sword",1+me->query_int()/6);
		        me->improve_skill("sword",1+me->query_int()/7);
		}
		else
		{
			msg = "$N想使出索極劍中的連發絕技，可是卻被$n給看破了。\n";
message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
		return;
	}
	else return;
}
	
int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }
