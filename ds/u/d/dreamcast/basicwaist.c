#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name(HIY"神"HIM"妖"HIW"巾"HIC"帶"NOR,({"dreamcast waist","waist"}) );
        set("long",@LONG
這是一條輕而堅韌的巾帶•
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",15);
                set("unit", "條");       
                set("value",1500);          
                set("volume", 3);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/con",2);
        setup();
}
