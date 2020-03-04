#include <ansi.h>
#include <weapon.h>
// mob_lv>=74
inherit BLADE;
void create()
{
  set_name(CYN"巫月神刀"NOR,({"moon blade","moon","blade"}));
set_weight(58000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("long","這是巫毒教的神器--巫月神刀,看起來相當的鋒利,\n"+
               "相傳在夜晚時是它威力最強的時候。\n");
    set("value",8085);
    set("material", "blacksteel");
    set("wield_msg","$N從背後拔出一把$n\n");
//  set("weapon_prop/parry",2);
    set("weapon_prop/attack",4);
    set("unequip_msg", "$N手中的$n放入背後。\n");
	set("blade",210);
    init_blade(1470);	//功擊力
  }

  setup();

}
