#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
  set_name(HIG"巨鵰爪"NOR , ({ "biggest-chisel claw","claw" }) );
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "碧眼巨鵰的爪子，鋼硬如鐵，攻擊力可大大的提升。\n");
    set("material", "gold");
    set("value",5000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",-1);  
  }
  init_fist(45);
  setup();
}


