#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(HIW"拂心塵"NOR, ({ "horsetail whisk", "whisk"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "隻");
                set("value", 150);
                set("material", "wood");
                set("wield_msg", "$N優雅的從背後抽出$n，拿在手上。\n");
                set("unwield_msg", "$N將$n插回背後。\n");
        }
        init_hammer(25);
        setup();
}
