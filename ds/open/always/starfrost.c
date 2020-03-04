#include <armor.h>
#include <ansi2.h>

inherit PANTS;

void create()
{
     set_name(HIY"琉璃"HIC"星霜"NOR, ({ "Lazurite star frost", "frost" }) );
	set_weight(10000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("long", @long
這件裝備傳說是從太古時代流傳至今的，據說共有十二位名匠共
同打造而成的。它主要的材料是琉璃，還有些許的翡翠、水晶，
表面看起來近似透明，卻又散發著不凡的光芒，像星光、又像冰
霜，故古人命其『琉璃星霜』。

Mid-Autumn Festival Gifts By -Alickyuen@The.Dream.Of.Seven
long);
		set("unit", "條");
                set("value", 1);
                set("no_sell", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sac", 1);
		set("material", "diamond");
	}
	set("armor_prop/wit", 1);
	set("armor_prop/shield",15);
	set("armor_prop/armor",25);
	setup();
}

int query_autoload() { return 1; }

void init()
{
	object me= this_player();

	if( !me ) return;
	if( environment(this_object()) == me )
	{
		if( !this_object()->query_light() ) this_object()->start_light(1);
  	}
}
