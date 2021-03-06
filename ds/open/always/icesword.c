#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIC"寒冰劍"NOR, ({ "ice sword","sword" }) );
	set_weight(12100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把寒冰劍十分細緻, 劍身透明略帶藍色, 劍刃極其鋒利,\n"
                            "是一把不可多得的神兵利器。\n[可儲存裝備]\n");
		set("value", 4300);
		//set("no_sell",1);
		set("no_sac",1);
		set("material", "ice");
	}
    set("weapon_prop/bar",1);
    set("weapon_prop/tec",-1);
    set("weapon_prop/hit",8);
    set("weapon_prop/parry",8);
    set("wield_msg",HIC"$N"HIC"將腰邊$n"HIC"緩緩抽出, 這裡的氣溫突然急劇下降!!\n"NOR);
    set("unwield_msg",HIC"$N"HIC"將$n"HIC"上的薄冰拭去, 迅速的將"HIC"$n"HIC"插回腰上的劍鞘中。\n"NOR);
    init_sword(20);
    setup();
}

void attack(object me,object victim)
{
  ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(40)) return; // 1/40 的機率出現特攻
	message_vision(HIC"$N"HIC"手上的$n"HIC"緩緩散發出陣陣的寒氣。\n"NOR,me,this_object());
	tell_object(me,"你似乎被凍傷了，動作不太靈活。\n");
	tell_object(victim,"你似乎被凍傷了，動作不太靈活。\n");
	me->receive_damage("hp",10+random(me->query("level")));
	me->add_busy(1);
	victim->receive_damage("hp",20+random(victim->query("level")*2));
	victim->add_busy(1);
	return;
}

int query_autoload() { return 1; }
