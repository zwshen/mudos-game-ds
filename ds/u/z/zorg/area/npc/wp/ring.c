#include <path.h>
#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit FINGER;
void create()
{
	set_name(HIC"能量戒子"NOR,({"powerful ring","ring"}));

	set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",HIB"這是一枚不尋常的戒子，看來這戒子有一些特別之處。\n"NOR);	    
                	set("unit", "枚");
		set("value",4000);
         		set("limit_skill",60);
		set("material", "starring");
		set("limit_str",32);
		set("armor_prop/armor", 10);
		set("limit_dex",20);
	}
	set("wear_msg","$N從袋裡拿出$n戴在手上！\n");
	set("remove_msg", "$N將手中的$n小心收好。\n");
	set("replica_ob", __DIR__"ring2.c");
	setup();
}
void defend(object me,object victim)
{
	int damage,str,dex,random1;
	if( random(150)>100)
	{
	str = me->query("str")-random(20);
	dex = me->query("dex")-random(18);
	random1 = 1+random(2);
	damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
	message_vision(
	"\n"
	+HIG"$N的能量戒子突然發出一道刺熱的激光\n"NOR
	+HIR"結果造成$N"+damage+"點的傷害！！！！\n"NOR
	,victim);
	return;
	}
}
