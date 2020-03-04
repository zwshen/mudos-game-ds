#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(WHT"ÅKµ·¥~¦ç"NOR,({ "iron cloth","cloth" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅKµ·½s¦¨ªº¤W¦ç[0;1;36m¡[1mA[0m«D±`»´¥©[0;1;36m¡[1mC[0m\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",500);
                set("armor_prop/dodge", 6);
                
        }
        setup();
}

