#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIW"薄雲"HIC"藍靴"NOR, ({ "blue_boots", "boots"  }) );
        set("long",
                "這是一件輕飄飄的長靴, 雖然很薄, 但是防禦力卻很高,
算是很好的護具了, 可是要有很高的速度才能操控。\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("armor_prop/armor",  12);
                set("armor_prop/shield",  10);
                set("armor_prop/dex", 2);
                set("limit_dex",25);
                set("material", "silk");
        }
        setup();
}
