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
                set("unit", "面" );
                set("value",20000);
                set("armor_prop/armor",  12);
                set("armor_prop/con", 2);
                set("armor_prop/str", 3);
                set("limit_level",15);
                set("material","fur");
        }
        setup();
}
