#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(WHT"ÅK¸yµP"NOR,({ "iron waist","waist" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅK³y¦¨ªº¸y¶¡ÅKµP¡A¨¾¿m¤O°ª[0;1;36m¡[1mC[0m\n");
        set_weight(700);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",700);
                set("armor_prop/armor", 7); 
                               
        }
        setup();
}

