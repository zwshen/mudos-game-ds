#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("Arai皮衣" ,({ "arai cloth","cloth" }) );
        set("long",@LONG
這是一件日本進口的Arai皮衣，上面有各個贊助商的商標，非常的花俏。
LONG
);
        set_weight(1200);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
                set("material", "skin");
                set("unit", "件");
                set("limit_level",30);
        }
        set("armor_prop/armor",22);
        set("value",19000);
        set("volume",20);
        setup();
}
int query_autoload() { return 1; }
