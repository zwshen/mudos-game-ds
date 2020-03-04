#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
     set_name(HIC"∂W¿s®Ó¶°ÒZ•“"NOR, ({ "dragon plate","plate" }) );
     set_weight(500);
     if ( clonep() )
          set_default_object(__FILE__);
          
     else {   
              set("unit", "•Û");
              set("material", "steel");
              set("value", 20000);
set("armor_prop/dodge",-50);
 set("armor_prop/armor",100);
           }
           setup();
}    
