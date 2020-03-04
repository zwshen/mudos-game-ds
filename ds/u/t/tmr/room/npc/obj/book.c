// force_book.c

inherit ITEM;

void create()
{
	set_name("侣", ({ "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "セ");
		set("long",
			"硂セ侣眎常竒獂独Τㄇ格家絢\n"
			"矗ㄇ㊣よ猭ぐ或\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"force",		// name of the skill
			"exp_required":	0,				// minimum combat experience required
											// to learn this skill.
			"sen_cost":		30,				// gin cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	10				// the maximum level you can learn
											// from this object.
		]) );
	}
}
