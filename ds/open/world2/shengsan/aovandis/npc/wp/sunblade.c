#include <weapon.h>
#include <combat.h>
inherit BLADE;

void create()
{
set_name("烈日刀",({"sun blade","blade"}));
set("long",@LONG
一把紅色握柄的大刀。刀身上面挖空狀若火焰，刀柄末
端還繫了一條有紅點白色的緞帶，你再仔細一看才知道那是
一塊塊的血跡。
LONG
);
	set_weight(11300);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("material","iron");
		set("no_sac",1);
        }
        set("value",5480);
    	set("weapon_prop/bar",1);
    	set("weapon_prop/sou",-1);
	set("weapon_prop/parry",5);
    	set("weapon_prop/blade",6);
	set("backstab_bonus",36);
	init_blade(22);
	setup();
}

void attack(object me,object victim)
{
        ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(9)) return; // 1/9 的機率連攻
	COMBAT_D->do_attack(me, victim, this_object(), TYPE_REGULAR);
	return;
}

