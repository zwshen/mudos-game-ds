#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("梟形武衣", ({ "owl cloth","cloth" }) );
        set_weight(3000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件有梟形裝飾的武師衣.\n");
                set("unit", "件");
                set("material","skin");
                set("armor_prop/armor", 6);
        }
        setup();
}
