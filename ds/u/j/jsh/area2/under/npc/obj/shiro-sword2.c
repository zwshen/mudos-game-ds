#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name("長劍", ({ "long sword" , "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
                set("long", "一把長劍，沒什麼特別的地方。\n");
                set("value", 1000);
        }
        init_sword(35);
        setup();
}

