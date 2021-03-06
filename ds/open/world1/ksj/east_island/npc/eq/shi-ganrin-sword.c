#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIG"丙子"HIY"觀林劍"NOR, ({ "shi-ganrin sword","sword" }) );
  set("long",@long
劍刃採用特殊鍛造方式製造，幾乎不會損壞，劍柄則是用銅鐵銀交嵌
出美麗的鳳舞梧林圖案。
long);      
  set_weight(2850);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",10500);
    set("volume",4);
    set("rigidity",1100);
    set("limit_skill",50);
    set("limit_lv",30);
    set("weapon_prop/int",1);
  }
  init_sword(58);
  set("wield_msg","$N拔出腰間的$n，令人不由得讚嘆其華麗。\n"NOR);
  set("unwield_msg","$N挽個劍花，輕巧地將$n收回劍鞘中。\n");
  setup();
}
