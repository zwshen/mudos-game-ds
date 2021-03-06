#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create()
{
  set_name(HIW""BLK"獸骨之爪牙"NOR, ({ "black-dog bone","bone" }) );
  set("long",@LONG
影犬之屍骸，呈現漆黑的色澤，勉強可以當作武器使用，似乎有特別
的功能。
LONG);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "對");
    set("value",0);
    set("material", "stone");
    set("volume",5);
    set("no_repair",1);
  }
  set("limit_lv",40);
  set("weapon_prop/wit",-1);
  set("weapon_prop/sou",-1);
  init_fist(25,TWO_HANDED);
  set("beast_weapon_prop/str", 50);
  setup();
  set("wield_msg","$N將$n帶著尖牙的頭骨裝在右手，左手則拿著有著利爪的腳骨。\n"NOR);
  set("unwield_msg","$N將$n收回到腰上的布囊中。\n");
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
