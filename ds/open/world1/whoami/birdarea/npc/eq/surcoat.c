#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"薄雲"HIC"披風"NOR ,({ "cloud surcoat","surcoat" }) );
        set("long","這是一件輕飄飄的披風, 雖然很薄, 但是防禦力卻很高,
算是很好的護具了。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1500);
        set("value", 8000);
        set("unit", "件" );
        set("material", "silk");
        }
        set("armor_prop/armor", 15);
        set("armor_prop/dex", 2);
        set("limit_dex",25);
        setup();
}

