#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
	set_name(CYN"神武護腰"NOR ,({ "god waist","waist" }) );
        set("long","神武教掌門人所配帶的護腰。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(8000);
                set("material", "skin");
                set("unit","條");
                set("value",2000);
                set("volume",1);
                set("armor_prop/armor", 4);
                set_temp("apply/hit",3);
                set("limit_int",20);
        }
        setup();
}

