#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name(HIM"舞"NOR"之"MAG"風",({"ba-chi cloak","cloak"}) );
        set("long",@LONG
天下不可多得的防具之一
LONG
);
        set_weight(999);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",13);
                set("unit", "頂");
                set("value",1500);
                set("volume", 2);
                set("material", "silver");
        }
        set("armor_prop/armor",20);
        set("armor_prop/con",4);
setup();
}
