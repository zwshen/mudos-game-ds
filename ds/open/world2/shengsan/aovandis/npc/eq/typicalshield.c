
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("���ɬ޵P",({"riot shield","shield"}) );
	set("long","�o�O���Z�}���u�éҸ˳ƪ����ɬ޵P�C\n");
	set_weight(6600);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
		set("value",2460);
	}
	setup();
}
