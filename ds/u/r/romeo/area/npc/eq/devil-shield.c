#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
        set_name(HIB "魔星幻盾" NOR,({ "devil-shield","shield" }) );
        set("long",
"這是一塊由千年寒鋼所製的盾牌，十分的堅硬。\n"
);
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "面" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/int", 1);
        }
        setup();
}
