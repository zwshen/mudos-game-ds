#include <armor.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name( "瘆年︾狝" ,({ "worn-out cloth","cloth" }) );
        set("long",
"ン瘆瘆年年︾狝癬ㄓ偶籇癬ㄓ篘癬ㄓ翲翲\n"
"程琌ぃ璶...\n"
);
        set_weight(105);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
        set("unit", "ン" );
        set("value",0);
        set("armor_prop/armor",-5);
        set("armor_prop/dex",-5);
        }
        setup();
}
