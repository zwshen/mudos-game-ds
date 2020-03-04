#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(HIY"虎牙匕首"HIR"(S)"NOR,({"tiger dagger","dagger"}));
  set("long",@LONG
劍牙巨虎的牙齒製成的匕首，相當尖銳。
LONG
);
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "把");        
    set("value",100000);
    set("volume",2);
    set("material","steel");       
  }        
  set("weapon_prop/str",1);         
  init_dagger(37);
  setup();
}

int query_autoload() { return 1; }

