
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�F��",({"salad"}) );
	set_weight(500);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�A�ݤ��X������S�O���a��,�]�\\�u�O�@�L���q���F�ԡC\n");
	set("unit", "�L");
	}
	set("value",100);
	set("food_remaining",3);
	set("heal_hp",20);
	set("heal_ap",13);
	setup();
}
