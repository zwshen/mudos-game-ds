#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIB "威爾鋼"NOR, ({ "pill" }));
        set("long","這一顆是由美國進口的藍色小藥丸，十分珍貴喔。\n");
        set("weight", 20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "粒");
              set("value", 1750);
              set("heal_hp",200);
              set("heal_mp",200);
             set("heal_ap",170);
              set("food_remaining", 1);
        }
        setup();
}
