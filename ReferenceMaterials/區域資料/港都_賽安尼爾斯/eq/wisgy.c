#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIB"«Â¤h§Ò"NOR, ({ "wisgy" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","¬Ó®c¶Q±Ú©Ò¶¼ªº¶¼«~¡A»ù­È¤£¤Z¡C\n");
                set("unit","ªM");
        }
        set("value",200);
        set("heal_ap",30);
        set("water_remaining",3);
        setup();
}
