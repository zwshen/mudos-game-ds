#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(WHT"ÅK¬ÞµP"NOR,({ "iron shield","shield" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅK¥´³yªº¬ÞµP[0;1;36m¡[1mA[0m¨¾¿m¤O°ª[0;1;36m¡[1mC[0m\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",1000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",10);
        }
        setup();
}

