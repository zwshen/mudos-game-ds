#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
        set_name(HIR"聖誕"HIW"長褲" NOR ,({ "christmas pants","pants" }) );
        set("long",@LONG
這是一件大紅長褲，顯得非常喜氣洋洋。 
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "條");
                set("value",1);
        }
        set("armor_prop/armor",1);
        setup();
}

