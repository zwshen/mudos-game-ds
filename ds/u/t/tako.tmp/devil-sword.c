#include <weapon.h>

#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIR"狂煞"MAG"魔"HIW"劍"NOR, ({"devil sword","sword"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "把");
         set("long", "暗天界第三種族最厲害的一把劍。\n");
         set("value", 3000);
         set("wield_msg", "$N"HIW"運用了天地的力量,一煞間藍光四散,一把$n"HIW"就在手上了。\n");
         set("unwield_msg", "$N"HIW"虎喝一聲,把內勁散去,$n"HIW"的光芒也隨之消逝了。\n");
         set("weapon_prop/str", 2);
         set("weapon_prop/con", 2);
         set("weapon_prop/dex", 3);
         set("weapon_prop/int", 1);
         set("weapon_prop/dodge", 40);
  }
    init_sword(99);
    setup();
}
