
#include <weapon.h>
inherit FORK;
void create()
{
        set_name("荒野鏢槍",({"field spear","spear"}) );
        set("long","這是一把長的標槍，適合在荒野草地的環境戰鬥或是打獵。\n");
          set_weight(5200);
        if (clonep() )
             set_default_object(__FILE__);
        else {
       		set("unit","桿");
         	set("value", 2000);
			set("volume", 4);
        	set("material","iron");
        	init_fork(40);
		}
        setup();
}

