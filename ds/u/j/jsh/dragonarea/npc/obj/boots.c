#include <ansi.h> 
#include <armor.h>
inherit BOOTS;

void create() 
{
        set_name(HIW"彈簧鞋"NOR,({ "up boots","boots" }) );
        set("long","光之子祖傳的鞋子，鞋底的彈性特別好，就像彈簧般似的，很有彈力。\n");
        set_weight(8000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","skin");
                set("unit", "件" );
       set("value",3500);
                set("armor_prop/armor", 8);
                set("armor_prop/dodge",10);
        }
        setup();
}

