#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("Arai護膝",({"arai kneecap","kneecap"}) );
        set("long",@LONG
這是一對日本進口Arai護膝，材質相當的堅硬。
LONG
);
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "plastic");
                set("unit", "對");
                set("limit_level",30);
        }
        set("armor_prop/armor",10);
        setup();
        set("value",14000);
        set("volume",6);
}
int query_autoload() { return 1; }
