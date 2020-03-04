#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(WHT"ÅKµ·¿Ç"NOR,({ "iron pants","pants" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅKµ·½s¦¨ªº¿Ç¤l¡A«D±`»´¥©[0;1;36m¡[1mC[0m\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",600);
                set("armor_prop/armor", 2); 
               set("armor_prop/dodge", 3);
                
        }
        setup();
}

