
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�p�ѥ]", ({ "small bread","small","bread" }) );
	set_weight(10);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","��...�n�����ѥ]�C\n");
	set("unit", "��");
	set("value",10);
	set("food_remaining",2);
	}
}
