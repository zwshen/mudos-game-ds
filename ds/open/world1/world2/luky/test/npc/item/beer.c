// dumpling.c

inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("��s", ({ "beer" }) );
	set_weight(360);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�@�~�ܴ��q����s�C\n");
		set("unit", "�~");
		set("value", 25);	//�Ѧһ��欰�^�_�I���`�M���H5
		set("heal_mp",22);	//�i�H�O"heal_hp"�άO"heal_mp",�]�i�H����.
		set("water_remaining", 3);
	}
	setup();
}