#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("神武披風" ,({ "god surcoat","surcoat" }) );
        set("long","這是一件神武教內門徒專用的披風，相當的輕巧。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "silk");
        set("unit", "件" );
        set("value",400);
set("volume",3);
        }
          set("armor_prop/armor", 5);
          set("armor_prop/int", 1);
        setup();
}
