#include <armor.h>

inherit WAIST;

void create()
{
        set_name("半獸人腰帶", ({ "orc belt" , "belt" ,}) );
        set_weight( 1500 );

        if( !clonep() ) {
                set("unit", "條");
                  set("value", 500);
                set("long" , @LONG
這是一條造型特殊的腰帶，似乎純以獸皮編織而成，上頭還殘留
些許的血腥味。
LONG
                                );
               set("armor_prop/armor", 4);
        } else
		   set_default_object(__FILE__);
        setup();
}

