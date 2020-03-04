#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name(HIW""BLK"黑龍爪"NOR,({"dragon claw","claw"}) );
  set("long","一隻漆黑的龍爪，表層微微透出一絲血光。\n");
  set_weight(3000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit","隻");
    set("value",12000);
  set("material","leather");
    set("volume",3);
    set("wield_msg","$N裝備$n"NOR"當武器，感到一股殺意湧上心頭。\n" NOR);
  }
  set("limit_skill",70);
  set("weapon_prop/str",2);
  set("weapon_prop/dex",-2);
  set("weapon_prop/hit",10);
  set("beast_weapon_prop/damage",62);
  set("beast_weapon_prop/hit",10);
  init_fist(61);
  setup();
}
