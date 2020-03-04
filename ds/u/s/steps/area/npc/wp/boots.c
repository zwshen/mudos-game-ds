#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"天使羽靴"NOR,({ "angel-feather boots","boots" }) );
        set("long",HIY"傳說是由天使之翼的羽毛造成的靴。\n"NOR);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(700);
        set("material", "feather");
        set("unit", "個" );
        set("value",10000);
        set("armor_prop/armor", 4);
        set("limit_dex",40);
        set("armor_prop/dex", 6);
        set("armor_prop/int", 6);
        }
        setup();
}
