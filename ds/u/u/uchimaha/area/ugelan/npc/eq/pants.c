#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name("´Ö¥¬µu¿Ç"NOR, ({ "short pants","pants" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","¤@¥ó¬ï¹Lªºµu¿Ç¡E\n");
                set("unit", "Âù");
                set("value",100);
                set("material", "fur");
                set("armor_prop/armor", 5);
        }
       setup();
}
