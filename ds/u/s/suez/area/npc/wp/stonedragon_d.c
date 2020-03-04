#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
set_name("石龍刺",({"stone-dragon teeth","teeth","dagger"}));

set_weight(2500);
          if( clonep() )
                      set_default_object(__FILE__);
          else {
set("long","這是從傳說中的石龍身上取得的牙齒，而這把更是經由名匠精\n"
              "心打造而成，表面像石頭般的顏色卻散發出珍珠般的光澤。\n");
set("unit", "根");
set("value", 3000);
set("material","rock");

set("limit_str",15);
set("limit_dex",10);

set("wield_msg", "$N將$n由象牙鞘中取出，柔和的光澤映在你的臉上。\n");
set("unwield_msg","$N小心翼翼的將$n放回象牙鞘中。\n");

set("weapon_prop/parry",15);
set("weapon_prop/hit",10);
init_dagger(25);
setup();
}
}                      
