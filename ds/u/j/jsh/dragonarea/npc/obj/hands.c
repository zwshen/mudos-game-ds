#include <ansi.h> 
#include <armor.h>
inherit WRISTS;

void create() 
{
        set_name(HIY"龍"HIW"型護腕"NOR,({ "dragon hands","hands" }) );
        set("long","一副龍型的護腕。\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",2000);
set("armor_prop/armor", 7); 
set("armor_prop/dodge", -2);
                
        }
        setup();
}

