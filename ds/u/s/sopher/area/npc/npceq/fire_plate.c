#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
     set_name(HIR"ª¢ÀsñZ¥Ò"NOR, ({ "fire dragon plate","plate" }) );
     set_weight(5000);
     if ( clonep() )
          set_default_object(__FILE__);
          
     else {   
              set("unit", "¥ó");
              set("material", "steel");
              set("value", 20000);
              set("armor_prop/armor", 500);
              set("armor_prop/dodge", -250);
           }
           setup();
}    
