#include <weapon.h>
inherit FORK;
void create()
{
        set_name("生鏽的長槍",({"rusty pike","pike"}) );
        set("long",@LONG
這只是一把生鏽的長槍。
LONG
	);
        set_weight(25000);
        if (clonep() )
        	set_default_object(__FILE__);
        else 
	{
        set("unit","桿");
        set("value",100);
        set("volume",5);
        set("material","steel");
        init_fork(1);
   	}
        setup();
}