#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("天妖披風" ,({ "devil surcoat","surcoat" }) );
        set("long","這是一件有如蝙蝠翅形的披風。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(6000);
        set("material", "skin");
        set("unit", "件" );
set("value",2400);
	set("volume",2);
     set("armor_prop/armor",10);
        set("limit_dex",3);
        set("armor_prop/str",2);
        set_temp("apply/dodge",-5);
        }
        setup();
}
