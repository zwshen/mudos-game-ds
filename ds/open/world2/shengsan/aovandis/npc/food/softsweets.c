
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�n�}", ({ "soft sweets","soft","sweets" }) );
	set_weight(160);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�n�Y�i�f���n�}�C\n");
	set("unit", "��");
	}
        set("heal_mp",15);
	set("value",15);
	set("food_remaining",1);
 setup();
}
