
#include <armor.h>

inherit NECK;

void create()
{
	set_name("�B�A����",({"jade necklace","necklace"}));
	set("long",@LONG
�o������O�ѳ\�h����⪺�B�A�ꦨ���A�A�������A���H�R������C
LONG
	);
	set_weight(850);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "��");
		set("value",725);
		set("armor_prop/shield",2);
	}
	setup();
}
