
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����}", ({ "milk candy","milk","candy" }) );
	set_weight(140);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�p�Ĥl�̳��w�������}�C\n");
	set("unit", "��");
	}
	set("value",10);
	set("food_remaining",1);
        set("heal_mp",9);
 setup();
}
