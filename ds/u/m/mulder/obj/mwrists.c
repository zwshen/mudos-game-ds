#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIG"小喇叭"HIC"專用護腕"NOR ,({ "mulder wrists","wrists" }) );
        set("long","這是一個小喇叭專用的防具。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "wrists");
        set("unit", "個" );
	set("no_sac",1);
	set("no_give",1);
	set("no_drop",1);
	set("no_sell",1);
        set("value",300);
        }
         set("armor_prop/armor", 100);
         set("armor_prop/con", 10);
         set("armor_prop/dex", 10);
         set("armor_prop/shield", 100);
         set("armor_prop/int", 10);
        setup();
}
int query_autoload() { return 1; }