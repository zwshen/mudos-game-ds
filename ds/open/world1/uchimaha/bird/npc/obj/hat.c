#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(MAG"埜狐面罩"NOR, ({ "fox mask", "mask"  }) );
        set("long","這是用殺人狐九尾身上的皮所製成的面罩, 雖然這只是
牠的皮, 不過還是感到有微微的殺意。\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張" );
                set("armor_prop/armor",  10);
                set("armor_prop/int", 3);
                set("limit_level",10);
                set("material","fur");
        }
        setup();
}
