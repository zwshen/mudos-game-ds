#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(WHT"ÅK¨B¨¬"NOR,({ "iron boots","boots" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅK³y¦¨ªº¾c¤l[0;1;36m¡[1mC[0m\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",600);
                set("armor_prop/armor", 5); 
               set("armor_prop/dodge", -3);
                
        }
        setup();
}

