#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(WHT"ÅKµ·©Ü­·"NOR,({ "iron surcoat","surcoat" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅKµ·½s¦¨ªº©Ü­·[0;1;36m¡[1mA[0m¥~«¬Áà­®[0;1;36m¡[1mA[0m¦ý¨¾¿m¤O°ª[0;1;36m¡[1mC[0m\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",800);
                set("armor_prop/armor", 10);
                
        }
        setup();
}

