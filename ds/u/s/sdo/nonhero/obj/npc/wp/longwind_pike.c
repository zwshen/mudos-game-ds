#include <ansi2.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name(HIG"長風槍"NOR,({"longwind pike","pike"}) );
        set("long",
        "長風槍，較一般的長槍長三尺，因此沒有一定的能力是拿不起來的。\n所以無上國的軍人無一不以能夠使用長風槍為榮。\n");
          set_weight(10000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","桿");
        set("value",2500);
        set("volume",4);
        set("material","iron");
        init_fork(35);
	}
	set("limit_str",30);
        setup();
}

