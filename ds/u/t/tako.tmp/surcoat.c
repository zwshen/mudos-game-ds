#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIG"青鎖繫肩"NOR ,({ "green surcoat","surcoat" }) );
        set("long","這是一件用鐵鍊綁成的披肩，相當的遲重。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "silk");
        set("unit", "件" );
        set("value",400);
set("volume",3);
        }
          set("armor_prop/armor", 25);
          set("armor_prop/int", 2);
          set("armor_prop/sword", 20);
          set("armor_prop/dex", -2);
        setup();
}


