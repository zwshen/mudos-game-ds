#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("水手服", ({ "pilot suit","suit" }) );
        set_weight(5000);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件給水手們穿的專用衣服，上面似乎有著阿泊兩字.\n");
                set("unit", "件");
        set("value",100);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}


