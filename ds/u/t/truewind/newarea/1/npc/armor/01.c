#include <armor.h>
#include <ansi.h>
inherit CLOTH; 
void create()
{
        set_name(HIW"喪服"NOR,({ "mourning cloth","cloth" }) );
        set("long","服喪時所穿的衣服，左襟上縫了一塊方形的亞麻布。\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","cotton");
        set("unit", "件" );
        set("value",500);
        set("armor_prop/armor", 2); 
        } 
        setup();
}  