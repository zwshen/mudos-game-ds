#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name("烈日寶甲", ({ "sun armor","armor" }) );
	set_weight(11000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
這是一件利用岩漿高溫打造的堅固寶甲。硬度可與鑽石相比，
鑄造這件寶甲的人已經不可考了，不過關於這件盔甲的傳說倒是不
少。
LONG
);
		set("unit", "件");
		set("material", "rock");
		//set("no_sell",1);
		set("no_sac",1);
		set("value",4800);
	}
	set("armor_prop/fire", 12); //火系防具.
	set("armor_prop/shield",10);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",20);
	setup();
}

