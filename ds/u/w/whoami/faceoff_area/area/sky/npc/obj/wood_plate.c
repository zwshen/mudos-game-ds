#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("青木令", ({ "wood plate","plate" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("value", 100);
                set("long", "一個苗家村的族長令牌");
                }
        setup();
}
