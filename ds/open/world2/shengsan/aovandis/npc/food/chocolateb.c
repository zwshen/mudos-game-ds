
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���J�O�y", ({ "chocolate balls","chocolate","balls" }) );
	set_weight(200);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�p���i�R�����J�O�y�C\n");
	set("unit", "��");
	}
        set("heal_mp",18);
	set("value",20);
	set("food_remaining",1);
 setup();
}
