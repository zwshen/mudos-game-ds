#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name("佛珠",({ "buddha's bead","bead" }) );
        set("long","這是出家人掛在脖子上的長串佛珠。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(999);
        set("material", "jade");
        set("unit", "串" );
         set("value",300)
          ;
        }
        set("armor_prop/armor", 1);
        set("armor_prop/dodge", 5);
        setup();
}
