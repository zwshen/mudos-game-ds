#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("荒野盔甲", ({  "field armor", "armor" }) );
		set("long", "這是一件由血腥荒野取得的盔甲，常被流浪在那邊的妖魔穿載著。\n");
        set_weight(3000);

		if ( clonep() )
  			 set_default_object(__FILE__);
		else {
                set("unit", "件");
                set("value", 500);   
                set("material", "iron");
        }
		set("armor_prop/armor",10);
        setup();
}


