#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void running_fire(object me,object target,int z,int damage);

mapping *action = ({
	([
	"action": "$N�����@�w�A�N�⤤���C���a�R���C��A\n�b�X$n���`�N�ɡA�@�|�ϥX�u���S���s�v�A��$n�ݤf��h�C",
	"damage":                30,
	"dodge" :                15,
        "damage_type":  "���", 
	]),
	([
	"action": "$N�j�ܤ@�n�A���t�ϥX�u���Ԧ۬١v�A�C�y��$n��W�����j�n�ަӥh�C",
	"damage":                20,
	"dodge" :                -5,
        "damage_type":  "����", 
	]),
	([
	"action": "$N�����믫�A�����k��A��b���j�ߤ����u�𨳳t���^�Ȥ��A\n�@�K�����A$N��C�ϥX�p÷���@�멹$n���W�g���ӥh�C",
	"damage":                25,
	"dodge" :                10,
        "damage_type":  "�@��", 
	]),
	([
	"action": "$N���ߤ@�ѽİʡA��C�ϥX�@�ۡu�p�üC�v�A\n�N�C���s���������@�멹$n���Y���{�h�C",
	"damage":                15,
	"dodge" :                -3,
        "damage_type":  "�ж�", 
        ]),
	([
	"action": "$N�q�y�ڮ��F�@�U�s�U�A�ܤF�@�ܡA���G�K�F�@��A\n�@���p�ߨϥX�u�s���K�H�v�A�K�p�s���@���$n�Ϊ������Ӧp��O�n�C",
	"damage":                20,
	"dodge" :                -15,
        "damage_type":  "���", 
        ]),
	([
	"action": "$N�ߤ��@���A�y��@�C�A�ߧY��$n�U�F�@�ۡu����F�v�A�C���K�p�������k�@��C",
	"damage":                23,
	"dodge" :                13,
        "damage_type":  "���", 
        ]),
	([
	"action": "$N�ϥX�@�ۥ����L�_�����c�C��$n���W�n�ަӥh�A���Ʀb�~�������ܬ��u���s�զ�v�A�ϧ�V$n�U�L�C",
	"damage":                18,
	"dodge" :                5,
        "damage_type":  "���", 
        ]),
	([
	"action": "$N�⾮�@�ۡu�|�c��Ѫ�v�A���۫K�r��$n��W�j�ޡA���ۤS�p�p��@�뻴�X����V$n�V���C",
	"damage":                17,
        "damage_type":  "�W��", 
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
			return notify_fail("�����C�k�èS���b�ϥΡC\n");
		me->map_skill("sword");
		me->reset_action();
		write("�ޯत���u�����C�k�v�w����ϥΡC\n");
		return 1;
	}

	if( !weapon)
		return notify_fail("�����D�ݭn�C�~��ϥΡC\n");

	if( weapon->query("skill_type")!="sword" )
		return notify_fail("�p�G�n�ϥί����C�k�A�h�����˳ƼC���Z���C\n");

	if( me->query("ap") < 20 )
		return notify_fail("�A����O�٤����H�ϥί����C�k�C\n");

	if( me->query_skill_mapped("sword")=="sorgi_sword" ) 
	{
		if( !target ) target = offensive_target(me);
		if( !target ) return notify_fail("�A�٦b�I�i�i�����C�k�j�C\n");
		if( !me->can_fight(target) ) return me->can_fight(target);
		if( !me->is_fighting(target)) me->kill_ob(target);
		if( !target->is_fighting(me)) target->kill_ob(me);
		c = target->query_armor();

		if( me->query_skill("sorgi_sword") > random(300) )  
		{
			msg = HIY"\n$N�ߤ��K�p���R�����@��A���a�@�a���D�A�@�ۡu�Ѷ����s�b�v�q$n����襩������$n���R���ӥh�I�I\n"NOR ;
			damage = me->query_skill("sorgi_sword") + me->query_damage() *1.5;
			damage -= random( target->query_armor() );
	 		if( damage < 40 ) damage = 40 + random(me->query_str());

	 		me->start_busy(2);

			if( random(me->query_skill("sorgi_sword")) > random(30) )
			{
				msg += HIM "$n���R�����B�Q$N��"+weapon->name()+"�@���L�h�A�@�D�������岪�����z�X�@�ά����H�G�T\n" NOR;
				target->start_busy(5);
				target->receive_damage("hp",damage,me);
				COMBAT_D->report_status(target);
			        me->improve_skill("sorgi_sword",1+me->query_int()/10);
			        me->improve_skill("sword",1+me->query_int()/10);
			}
			else
			{
				msg += HIY"$n�D�o�{$N���I��R�����B�A�ਭ���F�}�ӡC\n" NOR;
			}

			message_vision(msg, me, target);
			me->receive_damage("ap",25);
			return 1;
		}
		else
		{
			damage = random(me->query_skill("sorgi_sword")) + me->query_damage();
			damage -= random( target->query_armor() );
	 		if( damage < 55 ) damage = 55+random(me->query_str());
			i=( me->query_skill("sorgi_sword")+me->query_skill("fogseven"))/2;
			if ( i > 50 )i = 2;
			if ( i < 51 )i = 1;
			if ( i == 2 )
			{
				me->start_busy(3);
				call_out("running_fire",0,me,target,2,damage);
			}
			if ( i == 1 )
			{
				me->start_busy(2);
				call_out("running_fire",0,me,target,1,damage);
			}
			return 1;
		}
        }

	message_vision("\n"HIC"$N�j�ܤ@�n�A��������u���p���ݤf�¤��ӥh�I\n"NOR,me);
	me->map_skill("sword", "sorgi_sword");
	me->reset_action();
	me->receive_damage("ap", 7);
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

	if( me->query("ap")<10 )
	{
	 	me->map_skill("sword");
		me->reset_action();
		message_vision("\n"HIW"$N����O�����L�k�~��I�i�����C�k�C\n"NOR,me);
		remove_call_out("delay");
		return ;
	}

	if( me->is_fighting() ) me->receive_damage("mp",7);

	call_out("delay",8,me);
}

void running_fire(object me,object target,int z,int damage)
{
	string a="$N�����@�w�A�N�⤤���C���a�R���C��A\n�b�X$n���`�N�ɡA�@�|�ϥX�u���S���s�v�A��$n�ݤf��h�C\n",
	       b="$N�j�ܤ@�n�A���t�ϥX�u���Ԧ۬١v�A�C�y��$n��W�����j�n�ަӥh�C\n",
	       c="$N�����믫�A�����k��A��b���j�ߤ����u�𨳳t���^�Ȥ��A\n�@�K�����A$N��C�ϥX�p÷���@�멹$n���W�g���ӥh�C\n",
	       d="$N�q�y�ڮ��F�@�U�s�U�A�ܤF�@�ܡA���G�K�F�@��A\n�@���p�ߨϥX�u�s���K�H�v�A�K�p�s���@���$n�Ϊ������Ӧp��O�n�C\n",
	       e="$N�ϥX�@�ۥ����L�_�����c�C��$n���W�n�ަӥh�A\n���Ʀb�~�������ܬ��u���s�զ�v�A��C�w�ͥͪ���F���s�A��V$n���Ⲵ�C\n",
	       msg;

	if ( z==1 ) 
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_str())*2) )
		{
			a += HIR"���G�y��$n�@�B�ж�!!\n"NOR;
			message_vision(a, me, target);
                	target->receive_damage("hp", random(damage) , me );
			b += HIR"���G�y��$n�@�B�ж�!!\n"NOR;
			message_vision(b, me, target);
                	target->receive_damage("hp", random(damage) , me );
			c += HIR"���G�y��$n�@�B�ж�!!\n"NOR;
			message_vision(c, me, target);
                	target->receive_damage("hp", random(damage) , me );
		        me->improve_skill("sorgi_sword",1+me->query_int()/8);
		        me->improve_skill("sword",1+me->query_int()/7);
			me->receive_damage("ap",20);
		}
		else
		{
			msg = "$N�Q�ϥX�����C�����s�o���ޡA�i�O�o�Q$n���ݯ}�F�C\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
		return;
	}

	if ( z==2 )
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_str())*2) )
		{
			a += HIR"���G�y��$n�@�B�ж�!!\n"NOR;
			message_vision(a, me, target);
                	target->receive_damage("hp", random(damage) , me );
			b += HIR"���G�y��$n�@�B�ж�!!\n"NOR;
			message_vision(b, me, target);
                	target->receive_damage("hp", random(damage) , me );
			c += HIR"���G�y��$n�@�B�ж�!!\n"NOR;
			message_vision(c, me, target);
                	target->receive_damage("hp", random(damage) , me );
			d += HIR"���G�y��$n�@�B�ж�!!\n"NOR;
			message_vision(d, me, target);
                	target->receive_damage("hp", random(damage) , me );
			e += HIR"���G�y��$n�@�B�ж�!!\n"NOR;
			message_vision(e, me, target);
                	target->receive_damage("hp", random(damage) , me );
			me->receive_damage("ap",30);
		        me->improve_skill("sorgi_sword",1+me->query_int()/6);
		        me->improve_skill("sword",1+me->query_int()/7);
		}
		else
		{
			msg = "$N�Q�ϥX�����C�����s�o���ޡA�i�O�o�Q$n���ݯ}�F�C\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
		return;
	}
	else return;
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