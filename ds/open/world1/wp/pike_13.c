#include <weapon.h>
inherit FORK;
void create()
{
	set_name("短槍",({"short pike","pike"}));
	set("long",@LONG
這是一把有著鐵製尖頭的短木槍，檜木製的槍身上還纏繞著一條紅
布。

LONG
);
	set_weight(4800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("material","iron");
	}
	set("value",380);
	init_fork(13);
	set("backstab_bonus",16);
        setup();
}
int can_stab() { return 1; }