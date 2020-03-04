#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name("纏銀手套", ({ "silver gloves","gloves" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這雙手套十分的堅固牢靠, 而且戴在手上覺得十分的舒適,\n"
                           "這種手套十分少見, 可以接住一般利刃的攻擊。\n");
		set("unit", "雙");
		set("value",1500);
		set("material","silver");
	}
	set("armor_prop/armor",4);
	set("armor_prop/parry",25);
	setup();
}
