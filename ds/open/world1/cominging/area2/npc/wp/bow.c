#include <ansi.h>
#include <weapon.h>
inherit BOW;

void create()
{
	set_name(HIG"綠霑弓"NOR,({"green bow","bow"}));
	set_weight(9500);
        if( clonep() )
		set_default_object(__FILE__);
        else {
        	set("long","這是一把用木頭所做的弓，上面有兩個發口，好像很沉重的樣子，表面用綠色的不明物質塗滿，好像具有神奇的法力一般。\n");
		set("unit", "把");
		set("value", 2230);
		set("rigidity", 300);    // 硬度
		set("material","iron");
		set("limit_str", 4);
		set("weapon_prop/dex",-1);
	}
	init_bow(10);   // 肉搏傷害力 = set("weapon_prop/damage", 14);
	setup();
}