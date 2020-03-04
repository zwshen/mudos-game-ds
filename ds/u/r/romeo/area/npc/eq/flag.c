#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("王旗",({ "lord's flag","flag" }) );
        set("long",
"這面旗子又破又爛，沾滿了血跡，但是由上面的刺繡可以看出這
面旗子本來的主人非比尋常。沒錯！這就是古代帝王出征攜帶的王
旗。但是王旗的主人已死，旗子也不再光彩。不過你可以將他披在
肩上，以他剩餘的光芒來保護你。\n"
);
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "件" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/int", -1);
        }
        setup();
}

