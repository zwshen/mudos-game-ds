#include <weapon.h> 
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name("黑鋼短刺", ({ "black steal stabber" }) );
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把用純鋼所鍛造出的匕首，殺傷力不容小覷•\n");
                set("value", 1570);
                set("material", "steel");
        }
        init_dagger(35, SECONDARY);

        set("wield_msg", "$N從懷中摸出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n藏入懷中。\n");

        setup();
}

