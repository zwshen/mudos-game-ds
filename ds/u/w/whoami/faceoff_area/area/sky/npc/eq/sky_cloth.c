#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("天壇道衣", ({ "sky cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件祭天時所穿的布衣.\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/shield",4);
                set("armor_prop/armor", 5);
        }
        setup();
}

