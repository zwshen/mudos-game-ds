#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("羊皮帽" ,({ "wool hat","hat"}) );
        set("long","這是一頂由羊皮所縫紉而成的帽子。\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "fur");
        set("unit","頂");
		set("value",200);
        }
         set("armor_prop/armor", 2);
        setup();
}
