#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(HIY"���p�ֹu" NOR, ({ "big boots", "boots" }) );
	set("long","�o�O�@��x�h�Ҭ諸�c�l,�㦳�ܦn�����m�O\n");
	set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth" );
		set("unit", "��" );
		set("value" , 130);
		set("armor_prop/armor", 4);
		set("armor_prop/shield", 5);
	}
	setup();
}