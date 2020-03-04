#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("鋼鐵匕首", ({ "steel dagger", "dagger" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "這是一柄亮晃晃的匕首\n");
                set("value", 500);
                set("material", "steel");                
               set("backstab_bonus",15); //百分比
        }
        init_dagger(15);
        setup();
}

