
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("���[���٫�",({"red glazed ring","ring"}) );
	set("long",@LONG
�o�ӧ٫����۬��⪺�����A�A�ݥX���R������[���O�o�u�٫����F��Ҧb�C
LONG
	);
	set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "�T");
		set("value",650);
		set("armor_prop/shield", 3);
	}
	setup();
}
