#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("�j���",({"shield"}) );
	set("long","�o�O�@���j��ޡC\n");
	set_weight(1200);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
		set("value",220);
	}
	setup();
}
