#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIW"鋼靴" NOR, ({ "steel boots", "boots" }) );
        set("long","以鋼鑄成，擁有良好防禦力的一雙靴子，保護戰
士的腳不受傷害。\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel" );
                set("unit", "雙" );
                set("value" , 1000);
                set("volume",3);
                set("armor_prop/armor", 9);
        }
        setup();
}

