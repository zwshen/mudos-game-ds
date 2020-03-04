#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("雙刃刀", ({ "double blade","blade" }) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把罕見的雙刃刀, 模樣似刀, 但是其實有兩刃,\n"
                            "兵器學中, 單刃為刀雙刃為劍, 雖然你可以把它當劍用, \n"
                            "但是此刀的特性還是以刀法為主流, 想以劍術使此刀, 非\n"
                            "常容易傷到自身. 此刀需要相當高段的刀法和敏捷才可使\n"
                            "用。\n");
		set("value", 2500);
		set("material","steel");
		set("limit_skill",75);
		set("limit_dex",40);
	}
    set("weapon_prop/hit",20);
    init_blade(55);
    setup();
}
