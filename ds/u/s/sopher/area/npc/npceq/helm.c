#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(CYN"流雲之盔"NOR ,({  "helm"  }) );
        set("long","這是一個相當輕盈的深紅色頭盔。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "helmet");
        set("unit", "頂" );
         set("value",60);
        set("armor_prop/armor", 500);
        }
        setup();
} 
