#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name( "點液背鱗" ,({ "dab-aqua-armor","armor" }) );
        set("long",
"這是一大片「狡龍  點液」背上的鱗片，看其鱗片十分堅實渾厚。你\n"
"拿近鱗片想細看時，陡地發現整副鱗片散發出一股不知名的香味。\n"
);
	set_weight(12345);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
		set("volume",6);
        set("unit", "副" );
        set("limit_con",30);
        set("limit_level",15);
        set("value",4000);
	set("armor_prop/armor", 31);
	set("armor_prop/dex",-1);
        }
        set("beast_armor_prop/armor",31);
	set("beast_armor_prop/dex",-1);
	set("beast_armor_type","armor");
        setup();
}
