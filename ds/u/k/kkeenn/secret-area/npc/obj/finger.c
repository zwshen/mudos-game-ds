#include <armor.h>
inherit FINGER;
void create()
{
        set_name("神之戒指", ({ "god of finger","finger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一只神明專用的戒指, 不知為何落入人間的。\n");
                set("unit", "只");
                set("no_sell",1);
                set("no_sac",1);
                set("value",950);          
                set("wear_msg", "當$N把$n戴上的那一刻, 四周傳出天使的祝福!\n");
                set("unequip_msg", "$N的祝福被上蒼收回去了。\n");
           }
        set("armor_prop/dodge",1);
        set("armor_prop/armor",2);
        setup();
}

