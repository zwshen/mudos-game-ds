#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIW"龍牙項鍊"NOR,({ "necklace" }) );
        set("long","一條由龍牙串成的項鍊。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
         set_weight(50);
        set("material", "neck");
        set("unit", "個" );
        set("value",30);
 set("armor_prop/armor",3);
set("armor_prop/dex",1);
        }
        setup();
}
