inherit ITEM;

void create()
{
	set_name("骰子",({"dice"}) );
	set("long",@LONG
一個可以投擲(roll)的六面骰子。除了拿來賭博之外，看來也沒
有什麼用處吧。
LONG
);
	set_weight(20);
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","粒");
		set("value",10);
	}
	setup();
}

void init()
{
	add_action("do_roll","roll");
}

int do_roll(string arg)
{
	int m;
	object who;
	string num;
	who=this_player();

	if (arg != "dice") return 0;
	message_vision("$N從懷裡拿出一粒骰子，默念幾聲之後，一把擲在地上。\n",who);
	m=random(6)+1;
	switch(m) {
		case 6:
			num="６";
			break;
		case 5:
			num="５";
			break;
		case 4:
			num="４";
			break;
		case 3:
			num="３";
			break;
		case 2:
			num="２";
			break;
		default:
			num="１";
	}
      if(query("num")) num=query("num");
     message_vision("骰子滴溜溜地轉了幾圈之後，$N擲出了"+num+"點\n",who);
	return 1;
}
