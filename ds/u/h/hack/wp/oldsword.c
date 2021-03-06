#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
	set_name("【古劍】", ({ "old sword", "sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把劍刃面頗寬，寒光閃閃，是一柄不可多得的寶劍。\n"
                            "你注意到在寬闊的刃面上還以極小的字刻了一首古詩在\n"
                            "上面：\n"
			    "                  李都尉古劍\n"
                            "                    白居易\n"
                            "古劍寒黯黯，鑄來幾千秋。白光納日月，紫氣排斗牛。\n"
                            "有客借一觀，愛之不敢求。湛然玉匣中，秋水澄不流。\n"
                            "至寶有本性：精剛無與儔；可使寸寸折，不能繞指柔。\n"
                            "願快直士心，將斷佞臣頭；不願報小怨，夜半刺私仇。\n"
                            "勸君慎所用，無作神兵羞。\n"
                            "上面這些詩詞應就是取自中唐時代白居易之李都尉古劍\n"
                            "，修辭優美，且刻此詩至劍上的人實可謂巧奪天工！\n");
		set("volume",4);
		set("limit_skill",40);
		set("limit_con",35);
		set("limit_str",35);
       set("value",10000);
	set("material","blacksteel");
		set("replica_ob", __DIR__"steelsword");		
	}
	set("wield_msg", "$N將手中$n緩緩的由劍閘中取出握在手上。\n");
	set("unwield_msg", "$N將手中$n緩緩的放回劍閘之內。\n");
	set("weapon_prop/con",2);
	set("weapon_prop/dex",-2);
	set("weapon_prop/hit",20);
	init_sword(50,TWO_HANDED);
	setup();
}
void attack(object me,object victim)
{
	int damage,str,con,random1;
	if( me->query("ap") < 100 ) return;
	if(random(30) < 16) return;
	if( random(me->query_skill("sword",2)) > random(victim->query_dex()) )
	{
		str = me->query_str();
		con = me->query_con();
		damage = (str+con)+(me->query_damage()/2);
		damage = damage - (victim->query_armor()/3) - random(victim->query_armor()/3);
		damage = COMBAT_D->Merits_damage(me,victim,damage,"bar");
		if(damage > 250) damage = 250+random(10);
		victim->receive_damage("hp", damage, me );
		message_vision(
		"\n"
		+HIC"$N手中古劍寒光一閃，一道冷冽劍氣直迫$n而去！\n"NOR
		+HIM"結果$n走避不及，被劍氣劃中了身體！\n"NOR
		,me,victim);
		COMBAT_D->report_status(victim);
		me->receive_damage("ap",12);
		return;
	}
	else
	{
		message_vision("\n"+HIC+"$N手中古劍寒光一閃，一道冷冽劍氣直迫$n而去！\n"NOR+
				    MAG+"但是$n轉身避開了這一道劍氣。\n"NOR,me,victim);
		me->receive_damage("ap",10);
		return;
	}
}
