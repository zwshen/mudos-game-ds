#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(HIC"保險套"NOR ,({ "candom" }) );
        set("long","這是一只辦事用的保險套，隨丟隨用型。\n");
        set_weight(60);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "waist");
        set("wear_msg","$N戴上$n之後，忽然有一股想辦事的衝動\n");
        set("unit","只");
        set("value",1000);
        }
         set("armor_prop/armor", 3);
        setup();
}


