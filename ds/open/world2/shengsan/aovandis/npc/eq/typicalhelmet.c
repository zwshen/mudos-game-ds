
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("��Y��",({"typical helmet","helmet"}) );
	set("long","�o�O���Z�}���u�éҬ諸�Y���C\n");
	set_weight(3300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
		set("value",1400);
        	set("armor_prop/armor", 4);
	}
	setup();
}
