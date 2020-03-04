#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"¬õ¤ò«ü®M"NOR,({ "red finger","finger" }) );
        set("long","¤@¥u¥þ¨­¤ò¯ñ¯ñªº«ü®M[0;1;36m¡[1mA[0m¦n¹³¦³©_¯Sªº¯à¤O[0;1;36m¡[1mC[0m\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "¥ó" );
       set("value",1000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",10); 
                set("armor_prop/str",1);        }
        setup();
}

