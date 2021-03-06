#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(YEL"古紋匕首"NOR,({"primeval dagger","dagger"}));
  set("long",@LONG
七寸多長的青銅匕首，經由古代特殊鍛造方法製成，銳利程度可
以斷鐵分金，是罕見的名器。
LONG
);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "把");        
    set("value",10000);
    set("volume",2);
    set("material","steel");       
  }        
  set("weapon_prop/str",1);
  set("weapon_prop/dex",2);
  set("weapon_prop/hit",3+random(4));
  set("weapon_prop/dodge",5);
  set("weapon_prop/bio",random(2));     
  set("backstab_bonus",40);
  init_dagger(39+random(5));
  setup();
}
