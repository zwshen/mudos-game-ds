#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
        set_name("雷紋獬面",({ "lighting-unicorn-shield","shield" }) );
        set("long",
"這是面厚重的盾牌，正面刻了獬豸之面，突出的角代表了正義
，兩旁的雷紋則象徵摧毀敵人的怒吼！。\n"
);
        set_weight(7000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "塊" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/dex", -1);
        }
        setup();
}

