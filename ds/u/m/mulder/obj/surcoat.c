#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"武士披風"NOR ,({ "jedi surcoat","surcoat" }) );
        set("long","這是一件"HIW"『Jedi Knight』"NOR"專用的披風。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "surcoat");
        set("unit", "件" );
	set("no_sac",1);
	set("no_give",1);
	set("no_drop",1);
	set("no_sell",1);
        set("value",400);
        
          set("armor_prop/armor", 150);
          set("armor_prop/int", 10);
        }
        setup();
}
int query_autoload() { return 1; }