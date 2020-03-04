#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"•V©u≈ ¶±"NOR, ({ "winter song", "winter", "song" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","Aring±M•Œ....:P \n");
                set("unit", "•Û");
                set("material", "unknown");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("value",1);
        }
                set("armor_prop/armor", 120);
        setup();
}
int query_autoload() { return 1; }

