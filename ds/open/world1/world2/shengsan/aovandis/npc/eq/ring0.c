
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("�ȧ٫�",({"silver ring","ring"}) );
	set("long",@LONG
�ѯ»ȥ��y���٤l�A�{�ۻȥզ�ƥ@�������C
LONG
	);
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "silver");
		set("unit", "�T");
		set("value",350);
	}
	setup();
}
