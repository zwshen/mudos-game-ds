#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name("鋼盔" ,({ "helmet","helmet" }) );
	set("long","這是一頂官兵所穿載的頭盔，頭盔上頭還垂下了一大撮紅色鬚線\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
       set_weight(5000);
        set("material","iron");
		set("unit", "頂" );
		set("value",800);
	}
	set("armor_prop/armor", 8);
	setup();
} 
