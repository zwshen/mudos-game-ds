
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("�p���",({"small shield","shield","small"}) );
	set("long","�o�O�@����s���p��ޡC\n");
	set_weight(1220);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","wood");
		set("unit", "��");
		set("value",330);
	}
	setup();
}
