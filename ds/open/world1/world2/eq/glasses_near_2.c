#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("�������", ({ "nearsightedness glasses","glasses" }) );
	set("long",@LONG
�o�O�@�ƪ���T�ʫת��������C
LONG
);
	set_weight(580);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
//	set("armor_prop/show_damage",1);
	setup();
	set("value",650);
}

int query_autoload() { return 1; }