#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"薄雲"HIC"藍衫"NOR, ({ "blue_cloth", "cloth"  }) );
        set("long",
                "這是一件輕飄飄的衣衫, 雖然很薄, 但是防禦力卻很高, 
算是很好的護具了, 可是要有很高的速度才能操控。\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("armor_prop/armor",  20);
                set("armor_prop/shield",  10);
                set("armor_prop/dex", 2);
                set("limit_dex",30);
                set("limit_level",30);
                set("material", "silk");
                set("armor_prop/show_damage",1);
        }
        setup();
}


