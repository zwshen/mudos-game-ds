#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIY"靈光"HIW"項鍊"NOR,({"Dreamcast neck","neck"}) );
        set("long",@LONG
這是一條帶有靈光的項鍊，據說有不可思議的功效•
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");       
                set("value",200);          
                set("volume", 3);                       
                set("material", "wood");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/con",2);
        setup();
}

