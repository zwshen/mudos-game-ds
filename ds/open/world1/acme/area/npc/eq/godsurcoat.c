#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(CYN"神武披肩"NOR ,({ "god surcoat","surcoat" }) );
        set("long","神武教掌門人所穿戴之火紅色披肩。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(15000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","件");
                set("value",10000);
                set("volume",3);
                set("armor_prop/armor", 15);
                set("armor_prop/con", 1);
                set("limit_str",20);
        }
        setup();
}
