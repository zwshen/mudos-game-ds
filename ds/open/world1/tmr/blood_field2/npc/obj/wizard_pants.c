#include <armor.h>

inherit PANTS;

void create()
{
        set_name("土司短褲", ({ "toast pants", "pants" }) );
        set_weight(2500);
		set("long","相當罕見的短褲，是土人族群中荒野土司最愛穿的小花褲。");

        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "件");
                set("value", 500 );
        }

        set("armor_prop/armor",5);
        set("armor_prop/dex",1);
        setup();
}

