#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name(HIY"玄"HIW"光"HIR"護腕"NOR, ({ "light hands","hands" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","２００５過年特別活動紀念ＥＱ。表面發著微弱的光，十分奇特。");
                set("unit", "個");
                set("value",9999);
                set("no_sell", 1);
                set("no_auc", 1);
        }
        set("armor_prop/shield", 5); 
        set("armor_prop/con", 1);
        set("armor_prop/dex", 1);
        setup();
}
int query_autoload() { return 1; }
