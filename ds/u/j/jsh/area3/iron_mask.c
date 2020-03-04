#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(WHT"ÅK­±¨ã"NOR,({ "iron mask","mask" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅK¥´³yªº­±¨ã[0;1;36m¡[1mA[0m¨¾¿m¤O¤£®t[0;1;36m¡[1mC[0m\n");
        set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",300);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge",-2);
        }
        setup();
}

