#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("�ֹu",({"boots"}));
	set("long","�@���ΦѤ��֩Ұ����ֹu�A�ˤ]��ǭ@�i�C\n");
     set_weight(1500);
	if (clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","��");
        set("value",200);           
		set("volume",2);
	set("material","fur");
	set("armor_prop/armor",3);
	}
	setup();
}

