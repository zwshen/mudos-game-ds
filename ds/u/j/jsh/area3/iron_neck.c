#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(WHT"ÅK¶µÁå"NOR,({ "iron neck","neck" }) );
        set("long","³o¬O¤@¥ó§¹¥þ¥ÎÅK¥´³yªº¬ÞµP[0;1;36m¡[1mA[0m¨¾¿m¤O°ª[0;1;36m¡[1mC[0m\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",200);
                set("armor_prop/armor", 5);
                
        }
        setup();
}

