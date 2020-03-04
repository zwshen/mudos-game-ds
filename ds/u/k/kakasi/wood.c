#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ÀÌ¤ì", ({ "wood", "wood" }));
        set("long","¤ì§÷¤¤ªº·¥«~¡C\n");
        set_weight(450);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "®Ú" );
                set("value", 100 );
        }
        setup();
}
