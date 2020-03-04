#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name(HIB "魔星披風" NOR,({ "devil-manteau","manteau" }) );
        set("long",
"這是一件防水的披風，背後還繡上一隻猛虎看起來氣勢十足\n"
);
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "件" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/dex", 1);
        set("armor_prop/con", 1);
        }
        setup();
}
