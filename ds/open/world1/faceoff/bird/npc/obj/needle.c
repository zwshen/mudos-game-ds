#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("»È°w", ({ "needle", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "®Ú");
                set("long", "¤@®Ú°w¨b¥Îªº°w.");
		set("no_drop", 1);
		set("no_give", 1);
		set("no_sac", 1);
                }
        setup();
}
int query_autoload() { return 1; }
