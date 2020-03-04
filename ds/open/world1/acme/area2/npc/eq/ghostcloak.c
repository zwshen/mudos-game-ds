#include <armor.h>
inherit F_UNIQUE;
inherit SURCOAT;
void create()
{
        set_name("冥王天斗" ,({ "sky cloak","cloak" }) );
        set("long","這件斗蓬似乎有被特殊的法力加持過，雖然華麗但是\n"
                   "卻異常的具防禦力與耐用度。\n");
        set_weight(5000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
        set("unit", "件" );
		set("volume",4);
        set("value",8000);
        set("limit_lv",20);
	set("replica_ob",__DIR__"cloak");
        }
        set("armor_prop/armor",18);
        set("armor_prop/str",2);
        set("armor_prop/dodge",15);
        setup();
}
