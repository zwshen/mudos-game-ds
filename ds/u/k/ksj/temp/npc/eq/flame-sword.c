#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIR"炎之劍"NOR, ({ "flame sword","sword" }) );
  set("long",@LONG
由高熱熔岩形成的巨大火燄劍，光是高熱火燄就足夠將被擊中的物體
焚為灰燼。
LONG);
  set_weight(30000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "把");
    set("value",0);
    set("material", "stone");
    set("volume",10);
    set("no_repair",1);
  }
  set("limit_level",60);
  init_sword(100);
  set("beast_weapon_prop/str",70);
  set("beast_weapon_prop/bar",1);
  set("beast_weapon_prop/bio",1);
  set("beast_weapon_prop/hit",20);
  setup();
  call_out("dest_sword", 35);
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  COMBAT_D->do_attack(me, victim, this_object(), 4);
  COMBAT_D->report_statue(victim);
  return;
}

void dest_sword()
{
  message_vision(HIR"\n伊佛利特"NOR"隨手將燃燒殆盡的"RED"炎之劍"NOR"丟在一旁。\n\n"NOR,this_object());
  destruct(this_object());
}
