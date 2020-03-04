#include <weapon.h>

#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIR"落紅"HIW"劍"NOR, ({"down-red sword","sword"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "把");
         set("long", "一把略呈淡紅色的氣劍,但又有一種說不出來的透明感。\n");
         set("value", 150);
         set("wield_msg","$N伸右屈指,忽然紅光四散,一把$n就在你的手指上。\n");
         set("unwield_msg","$N喝一聲的,把內勁散去,$n的光芒也隨之消逝了。\n");
         set("weapon_prop/str", 3);
         set("weapon_prop/con", 2);
         set("weapon_prop/dex", 5);
         set("weapon+prop/int", 5); 
    }
    init_sword(70);
    setup();
}








