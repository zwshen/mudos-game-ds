#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
         set_name(HIY"神"HIW"光"HIC"護腕"NOR,({"Dreamcast hands","hands"}) );
        set("long",@LONG
這是光明大神手中所戴的護腕
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "雙");       
                set("value",1200);          
                set("volume", 3);                       
                set("material", "steel");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/str",2);
        set("armor_prop/tec",-1); 
        setup();
}

