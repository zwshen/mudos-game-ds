#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIY"馬靴" NOR, ({ "riding boots", "boots" }) );
        set("long","保養的閃閃發亮的一雙馬靴。\n");
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather" );
                set("unit", "雙" );
                set("value" , 500);
                set("volume",3);
                set("armor_prop/armor", 6);
                set("armor_prop/shield", 1);
        }
        setup();
}

