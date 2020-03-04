#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
     set_name(HIC"Å]ÀsñZ¥Ò"NOR, ({ "evil dragon plate","plate" }) );
     set_weight(5000);
     if ( clonep() )
          set_default_object(__FILE__);
          
     else {   
              set("unit", "¥ó");
              set("material", "steel");
              set("value", 20000);
              set("armor_prop/armor", 5000);
              set("armor_prop/dodge", 5000);
           }
           setup();
}    
