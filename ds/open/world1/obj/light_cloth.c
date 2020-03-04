#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"¬ÂÄn³½¥Ö"NOR, ({ "light cloth", "cloth" }) );
	set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±i");
                set("long", "³o¬O¬ÂÄn³½ªº³½¥Ö.");
                }
        setup();
}
