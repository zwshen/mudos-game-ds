#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name(HIR"竧较"HIW"フ腉"NOR,({ "christmas beard","beard" }) );
        set("long",@LONG
硂琌技フ︹腉ぃ笵ぐ或碞琌稱璶拦ウ 
LONG);
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","fur");
        set("unit","技");
        set("value",1);
        }
        set("armor_prop/armor",1);
        setup();
}

