#include <armor.h>

inherit WAIST;

void create()
{
	set_name("�ɨ�",({"jade"}) );
	set("long","�@�T�Υ��J�Z�Ӧ����ɨءC\n");
      set_weight(200);
        set("unit","�T");
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","�T");
        set("value",80);           
		set("material","jade");
		set("armor_prop/armor",1);
	}
	setup();
}
