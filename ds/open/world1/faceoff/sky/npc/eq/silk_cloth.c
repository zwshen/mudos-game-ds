#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"天蠶絲衣"NOR, ({ "silk cloth","cloth"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這是一件由天蠶絲所織成的衣服, 看起來相當的輕便....\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/shield",2);
        set("armor_prop/dex",2);
                set("armor_prop/armor", 12);
              set("wear_msg",HIW"$N穿上了天蠶絲衣.\n"NOR);
        }
        setup();
}

