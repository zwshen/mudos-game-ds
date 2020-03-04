#include <ansi.h>
#include <weapon.h> 
inherit FIST;

void create()
{
  set_name(HIB"發活"NOR , ({ "following-soul[claw]","claw","soul" }) );
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "р");
    set("long", "琌独う┮ゴ硑籈栋计笴活皌\n"
                "柑┮Τ骸る丁ゴ硑らる地發活\n");
    set("material", "gold");
    set("value",6000);
  }
  set("weapon_prop/str",1);
  set("weapon_prop/int",-1);   
  init_fist(44);
  setup();
} 
