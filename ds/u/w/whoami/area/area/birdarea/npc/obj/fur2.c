#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"天狗皮"NOR,({ "tengu fur","fur" }));
        set_weight(1300);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","傳說中的鳥人『天狗』身上的皮，似乎可以穿的樣子•\n");
                set("unit","張");
                set("value",700);
                set("material","fur");
        }
                set("armor_prop/shield",10);
                set("armor_prop/armor", 15);
                set("armor_prop/con",2+random(2));

        setup();
}

