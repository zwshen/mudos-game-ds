#include <armor.h>
inherit SURCOAT;
void create()
{
        set_name("天妖斗蓬" ,({ "tian-demon cloak","cloak" }) );
        set("long","這是一件萬惡之王「天妖」身披的天妖斗蓬，斗蓬上不時有血跡滲出，怪異之極。");
        set_weight(1200);
        if ( clonep() )
        set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",3);
                set("unit", "件");
                set("value",3500);
        }
        set("limit_con",20);
        set("limit_int",20);
        set("limit_level",25);
        set("armor_prop/armor",15);
        set("armor_prop/str",1);
          set("armor_prop/hit",5);
        setup();
}

