#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("僧鞋" ,({ "bonze's boots" , "boots" }) );
        set("long","這是一雙和尚穿的鞋子，並無特別之處。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1000);
        set("material", "linen");
        set("unit", "雙" );
        set("value",200);
        }
        set("armor_prop/armor", 3);
        set("armor_prop/dodge", 8);
        setup();
}
