// rewrite by cominging 4/4/00
// ok .. debug by cominging at 4/6/00 - bug 1. Dodge query_temp 和 add_temp 的正負號

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
  "$n隨地走了一走，竟然把$N的攻擊視若無睹的閃了過去。\n",
  "$n內力一提，閉目使心眼看，躲過了$N的攻擊。\n",
  "$n輕如神靈一般，輕鬆的躲過了$N的攻擊。\n",
  "$n使出"HIM"一幻玉兔閃"NOR"，輕而易舉的閃過$N猛烈攻勢。\n",
  "$n使出"HIM"二幻閃靈訣"NOR"，輕飄飄的閃過了$N的攻擊。\n",
  "$n施展"HIM"三幻蝴蝶飄"NOR"，隨著$N的游走，化解了$N的擊勢。\n",
  "$n凝聚身上之力，使出"HIM"四幻軟骨功\"NOR"軟綿綿的消去$N的攻擊。\n",
  "$n精氣再提，使出"HIM"五幻遁地"NOR"使得$N一時不知所措，趁此避過一擊。\n",
  "$n凝聚氣神，使出"HIM"六幻摧眠術"NOR"，$N腦中一時混沌，無法攻擊。\n",
  "$n使出"HIM"七幻影步訣"NOR"，突然幻影飄然，使得$N攻擊失誤。\n",
});	

int exert(object me, object target, string arg)
{
	string msg;
	int add_dodge = ((me->query_skill("dodge") * me->query_skill("fog_seven")) / (me->query_skill("dodge")+me->query_skill("fogseven") - 4))/1.01 + random((me->query_skill("dodge")+me->query_skill("fogseven"))/3);

	if ( arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="fogseven")
			return notify_fail("你並沒有使用迷幻七步訣。\n");
		if( me->query_temp("apply/dodge") >= me->query_temp("class_wind/fogseven") )
			me->add_temp("apply/dodge", -me->query_temp("class_wind/fogseven"));
		else me->set_temp("apply/dodge", 0);
		me->delete_temp("class_wind/fogseven");
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N又恢復回原來的速度了。\n"NOR,me);
		write( HIC"取消使用技能-閃避之技迷幻七步訣。\n"NOR );
		return 1;
	}

	if ( me->query_skill("dodge") < 5 )
		return notify_fail("你的輕功\基礎不夠無法使用迷幻七步訣。\n");

	if ( me->query_skill_mapped("dodge")=="fogseven" )
		return notify_fail("你正在使用迷幻七步訣。\n");

	if ( me->query("ap") < 10 )
		return notify_fail("你的身體目前狀況還無法使用迷幻七步訣。\n");

        if( !me->skill_active( "fogseven", (: call_other, __FILE__, "delay", me :), 10) )
		return notify_fail("你的迷幻七步訣收招動作還沒完成。\n");

	me->map_skill("dodge","fogseven");
	me->reset_action();

	message_vision("\n"HIB"一聲重重的喘息聲，$N把四骸之氣集壇中，心意會神，用心去體會迷幻七步訣的真義。\n"NOR,me);
	me->receive_damage("ap", 1);
	me->start_busy(1);
	if( !me->query_temp("class_wind/fogseven") )
	{
		me->add_temp("apply/dodge", add_dodge);
		me->set_temp("class_wind/fogseven", add_dodge);
	}
	else
	{
		if( me->query_temp("apply/dodge") >= me->query_temp("class_wind/fogseven") )
			me->add_temp("apply/dodge", add_dodge - me->query_temp("class_wind/fogseven") );
		else me->set_temp("apply/dodge", 0);
		me->add_temp("apply/dodge", add_dodge);
		me->set_temp("class_wind/fogseven", add_dodge);
	}
	return 1;
}

void delay(object me)
{
	int main, dodge, a;
	main = me->query_skill("fogseven") - 30;
	dodge = me->query_skill("dodge") - 30;
	a = main + dodge;


	if( !me ) return;

	if( me->query_skill_mapped("dodge") != "fogseven" )
	{
		if( me->query_temp("apply/dodge") >= me->query_temp("class_wind/fogseven") )
			me->add_temp("apply/dodge", -me->query_temp("class_wind/fogseven"));
		else me->set_temp("apply/dodge", 0);
		me->delete_temp("class_wind/fogseven");
		return;
	}

	if ( me->query("ap") < 10 )
	{
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N又回復到了一般的速度。\n"NOR,me);
		tell_object(me,"你的內息已亂，已無法再使用迷幻七步訣。\n");
		if( me->query_temp("apply/dodge") >= me->query_temp("class_wind/fogseven") )
			me->add_temp("apply/dodge", -me->query_temp("class_wind/fogseven"));
		else me->set_temp("apply/dodge", 0);
		me->delete_temp("class_wind/fogseven");
		return ;
	}

	if ( a > 1 ) a=1;
	if ( a < 0 ) a=0;
	if ( me->is_fighting() ) me->receive_damage("ap", 2-a);
	me->skill_active( "fogseven",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	return 1;
}

int improve_limite(object ob)
{
	if( ob->query("class1")=="疾風門" ) return 100;
	else return 115;
}