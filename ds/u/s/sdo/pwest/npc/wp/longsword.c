#include <weapon.h>
inherit SWORD;
void create()
{
   	set_name("長劍",({"long sword","sword"}));
   	set("long","一把隨處可見的長劍。\n");
   	set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("limit_str",10);
          	set("value",2000);
                set("volume",2);
                set("material","iron");
        }
	init_sword(20);
        setup();
}
