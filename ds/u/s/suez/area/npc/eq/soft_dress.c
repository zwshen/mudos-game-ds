#include <armor.h>

inherit CLOTH;

void create()
{
set_name("輕羅短衣",({"soft dress","dress"}) );

set_weight(275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","這是一件精巧的衣服，在手臂､胸口及背後是半透明的絲絹。\n"
                "沒有多餘的圖飾，卻能使穿上它的人更加迷人。不過，首要條\n"
                "件你要長的「很」好看才行。\n");
set("material", "silk");
set("unit", "件");
set("value",500);

//set("female_only");
set("armor_prop/armor", 1);
set("armor_prop/shield", 1);
        }
        setup();
}
