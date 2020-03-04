#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(WHT"ÅKÅ@µÃ"NOR,({ "iron hands","hands" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅK³y¦¨ªºÅ@µÃ[0;1;36m¡[1mC[0m\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",300);
                set("armor_prop/shield", 5); 
                set("armor_prop/armor", 20);
               
        }
        setup();
}

