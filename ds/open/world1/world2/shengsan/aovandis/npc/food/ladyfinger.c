
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�P��", ({ "ladyfinger" }) );
	set_weight(330);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�o���P��ݰ_�ӴN�ܦn�Y�C\n");
	set("unit", "��");
	}
	set("value",80);
	set("food_remaining",3);
        set("heal_ap",15);
 setup();
}
