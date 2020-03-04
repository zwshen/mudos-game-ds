#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(RED"¨¸"BLU"º»"HIR"¯P"HIW"¹u" NOR, ({ "Dreamcast boots", "boots" }) );
        set("long","³oÂù¹u¬O¨¸º»¤ý§Q¥Î´cÅ]¯PµK§@ªº¡E\n");
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather" );
                set("unit", "Âù" );
                set("value" , 130);
                set("volume",3);
                set("armor_prop/armor", 4);
                set("armor_prop/shield", 5);
        }
        setup();
}

