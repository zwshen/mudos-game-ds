#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"金絲袋"NOR, ({ "gold bag","bag" }) );
        set("long", 
"一口全用金色布料所製成的袋子，似乎蠻珍貴的。\n"
);
          set_weight(3000);
        set_max_capacity(50);
        set_max_encumbrance(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("volume",5);
                set("value",5000);
        }
        setup(); 
}
