#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(CYN"神武護腕"NOR ,({ "god wrists","wrists" }) );
        set("long","神武教掌門人所穿戴的護手。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(8000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","雙");
                set("volume",1);
                set("value",6000);
                set("armor_prop/armor", 3);
        }
        setup();
}
