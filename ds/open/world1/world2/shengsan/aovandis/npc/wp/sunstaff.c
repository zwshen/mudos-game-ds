#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name("太陽之杖", ({ "sun staff","staff" }) );
	set_weight(10350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這是一把古老的燃木杖，杖頭鑲了一顆神秘的紅色寶石，
當你觸摸到著這把木杖時，彷彿有一陣熱氣由手中傳來直達心
底。
[可儲存裝備]
LONG
);
		set("no_sac",1);
		set("material", "wood");
	}
    set("value", 4210);
    set("weapon_prop/sou",1);
    set("weapon_prop/bar",-1);
    set("weapon_prop/int",1);
    set("weapon_prop/parry",8);
    set("weapon_prop/perception",8);
    set("weapon_prop/hit",8);
//    set("wield_msg",HIC"$N"HIC"緊緊握住$n"HIC", 眼光似乎銳利了許\多!!\n"NOR);
//    set("unwield_msg",HIC"$N"HIC"沉著的將$n"HIC"插回腰間。\n"NOR);
    init_staff(18);
    setup();
}

void attack(object me,object victim)
{
        ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(21)) return; // 1/20 的機率出現特攻
	message_vision(HIM"$N"HIM"手上的$n"HIM"突然射出一顆火球。\n"NOR,me,this_object());
	message_vision(HIM"$N閃避不及而被火球擊中了。\n"NOR,victim);
	victim->receive_damage("hp",20+random(40-victim->query_temp("apply/ice")));
	return;
}

int query_autoload() { return 1; }
