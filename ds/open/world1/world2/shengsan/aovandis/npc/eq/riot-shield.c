
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("���ɬ޵P",({"riot shield","shield","riot"}) );
	set("long","�o�O���Z�}��ĵ�éҸ˳ƪ����ɬ޵P�C\n");
	set_weight(5400);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
		set("value",1960);
	}
	setup();
}
