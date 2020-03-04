#include <weapon.h>
#include <ansi.h>
inherit FIST;
void create()
{
	set_name("雨拳•雲手", ({ "rain cloud fist","fist" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "雙");
		set("long", "這是向雲堂主很寶貝的一件武器, 用於空手殺傷力頗強,\n"
                            "聽說是向雲堂主無意間獲得的。\n");
		set("value", 8000);
		set("material", "steel");
		set("limit_skill",30);
		set("limit_str",15);
		set("limit_con",15);
        }
    set("weapon_prop/dex",-2);
    set("weapon_prop/con",1);
    set("weapon_prop/int",-2);
    set("weapon_prop/str",1);
    set("weapon_prop/hit",10);
    init_fist(40);
    setup();
}
