#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"神龍尾"NOR, ({ "dragontail blade","blade" }) );
	set_weight(35000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "此刀重若千斤，形如三國時代關雲長所使的青龍偃月刀,\n"
                            "偌大的刀面上刻了一條龍，不過只有龍尾而已，不知道是啥\n"
			    "名堂的寶刀？\n");
		set("value", 35000);
		set("material", "steel");
		set("limit_skill",40);
		set("limit_str",55);
		set("limit_con",40);
		set("replica_ob",__DIR__"greatblade.c");
        }
    set("weapon_prop/bar",2);
    set("weapon_prop/tec",-2);
    set("weapon_prop/hit",-20);
    set("weapon_prop/dodge",-20);
    set("weapon_prop/dex",-4);
    init_blade(99,TWO_HANDED);
    setup();
}
void attack(object me,object target)
{
	int damage,def;

	if(me->query_skill("blade") > 50 && random(100)<10 && me->query_str() > 40 )
	{
	message_vision(HIC"$N手中的神龍寶刀忽然寒光一瞥，登時一條龍尾氣狂掃而出！\n" NOR,me,target);
	damage = me->query_skill("blade")+(me->query_str()/2)+random(me->query_str()/2);
	def = target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
	def = def/3;
	if(damage-def>0 && random(10)>5)
	{
	message_vision(RED "$N來不及閃避，已被一道狂烈龍氣砍中！\n"NOR,target);
	target->receive_damage("hp",damage-def);
	}
	else
	{
	message_vision(YEL "$N左閃右躲，好不容易躲開了龍氣的攻擊。\n"NOR,target);
	}

	}
	return;
}
