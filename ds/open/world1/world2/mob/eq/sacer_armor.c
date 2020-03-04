#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"白鼠皮衣"NOR ,({ "white fur cloth","cloth" }) );
        set("long",@LONG
        
  這是由鼠神的白色毛皮做製成的皮大衣，皮衣上有許多長長的軟毛
，由於其彈性極佳，伸縮力很好，所以即使體型特殊的人也可以輕易
穿上。柔軟的毛皮可以吸收大部分的衝擊力，由於鼠神神出鬼沒，是
一件傳說中的防具。
        
LONG
);
        set_weight(8900);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
        	set("material", "skin");
        	set("unit", "件");
        	set("limit_con",6);
        	set("value",8260);
	}
	set("no_sac",1);
	set("monster_armor_type","armor");
	set("monster_armor_prop/dex",2);
	set("monster_armor_prop/int",-1);
	set("monster_armor_prop/armor",19);
	set("monster_armor_prop/shield",8);
	set("armor_prop/dex",2);
	set("armor_prop/int",-1);
	set("armor_prop/armor",19);
	set("armor_prop/shield",8);
        setup();
}

int query_autoload() { return 1; }