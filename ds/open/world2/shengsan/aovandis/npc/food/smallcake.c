
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�p�J�|",({ "small cake","small","cake" }) );
	set_weight(350);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�o�Ӥp�J�|���o�Z��o���C\n");
	set("unit", "��");
	}
        set("heal_mp",9);
        set("heal_ap",21);
	set("value",30);
	set("food_remaining",1);
 setup();
}
