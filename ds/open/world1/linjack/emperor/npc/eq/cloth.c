#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("粗布短衫" ,({ "short cloth" , "cloth" }) );
        set("long","一件十分常見的短衫。\n");
        set_weight(400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value" ,50);
                set("material","linen");
        }
        set("armor_prop/armor", 3);
        set("armor_prop/shield", 2); 
        setup();
}
