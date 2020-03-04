#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(CYN"°©ÂÃ"HIR"¤§"HIW"µu¤b"NOR, ({ "hide-bone dagger","dagger" }) );
  set_weight(2100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "¬`");
    set("long", "¥H¤H°©¬°¤MÀTªºµu¤M¡A¤M¤bªxµÛ«CÂÅªº¨¸®ð¡C\n");
    set("value",3700);
    set("volume",3);
    set("material","blacksteel");
  }
  set("weapon_prop/dex",2);
  set("weapon_prop/hit",5);
  set("backstab_bonus",50);
  init_dagger(40);
  setup();
}
