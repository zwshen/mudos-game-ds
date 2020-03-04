#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(WHT"ÅK§Ù«ü"NOR,({ "iron ring","ring" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅK¥´³yªº§Ù«ü[0;1;36m¡[1mA[0m³y«¬¬üÆ[[0;1;36m¡[1mC[0m\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",100);
                set("armor_prop/armor", 3);
                set("armor_prop/shield",3);
        }
        setup();
}

