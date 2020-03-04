#include <weapon.h>

#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIC"靈力"HIW"劍"NOR, ({"power sword","sword"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "把");
         set("long", "一把略呈淡藍色的氣劍,但又有一種說不出來的透明感。\n");
         set("value", 150);
         set("wield_msg", "$N伸右屈指,忽然藍光四散,一把$n就在手指上了。\n");
         set("unwield_msg", "$N虎喝一聲,把內勁散去,$n的光芒也隨之消逝了。\n");
         set("weapon_prop/str", 2);
         set("weapon_prop/con", 2);
         set("weapon_prop/dex", 3);
         set("weapon_prop/int", 1); 
         set("weapon_prop/dodge", 40);
    }
    init_sword(99);
    setup();
}








