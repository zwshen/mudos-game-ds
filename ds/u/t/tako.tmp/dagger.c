#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
        set_name("虎柄椎" , ({ "tiger dagger","dagger" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("long", "這是在把柄處雕著虎頭的匕首，使將起來，定是虎虎生風。\n");
               set("value",1000);
               set("material", "iron"); 
               set("weapon_prop/dex", 30); 
set("weapon_prop/str", 15);
set("weapon_prop/dodge", 70);
set("weapon_prop/int", 20);
set("weapon_prop/con", 30); 
set("weapon_prop/sword", 70); 
set("weapon_prop/dagger", 70); 
set("weapon_prop/hide", 70);
set("weapon_prop/stealing", 70); 
set("weapon_prop/backstab", 70);
set("weapon_prop/sneak", 70);
        }
    init_dagger(100);
   setup();
}


