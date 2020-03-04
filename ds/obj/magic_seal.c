// magic_seal.c

inherit ITEM;

void create()
{
	set_name("才〨", ({"seal"}) );
	set_weight(5);
	set("long",
		"硂琌眎礶才〨ノ attach 盢ウ禟琘(┪琘)ō\n");
	set("unit", "眎");
}

int unequip()
{
	set("equipped", 0);
	return 1;
}

void init()
{
	add_action("do_attach", "attach");
}

int do_attach(string arg)
{
	string sheet, dest;
	object ob;
	function f;

	if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
		return notify_fail("Αattach <才〨> to <ヘ夹>\n");
	
	if( !id(sheet) ) return 0;

	ob = present(dest, this_player());
	if( !ob ) ob = present(dest, environment(this_player()));
	if( !ob ) return notify_fail("璶癸ぐ或狥﹁ㄏノ硂眎才〨\n");

	if( !functionp(f = query("attach_func", 1)) )
		return notify_fail("硂眎才⊿Τノ\n");

	if( evaluate(f, ob) ) {
		if( ob!=this_player() )
			message_vision("$N眎" + name() + "┕$n禟\n", this_player(), ob);
		if( ob && ob->is_character() ) {
			move(ob);
			set("equipped", "sealed");
			set("no_drop", "硂妓狥﹁ぃメ斌ゲ斗ノ detach\n");
		} else destruct(this_object());
		return 1;
	} else 
		return 0;
}
