#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"不點的皮"NOR ,({ "dkfum" }) );
        set("long","這是不點身上脫下來的皮。\n"NOR);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("no_sac",1);
        set("material", "peel");
        set("unit", "張" );
                set("value",10);
        }
        set("armor_prop/armor", 1000);
        set("armor_prop/id",({"Dkfum"}));
        set("armor_prop/name",({"不點"}));
        set("armor_prop/short",({"不點(Dkfum)"}));
set("armor_prop/long",({"看起來就很欠打的怪人。\n"}));
        setup();
} 

