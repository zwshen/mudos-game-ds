// dumpling.c

inherit ITEM;
inherit F_PILL;

void create()
{
	set_name("黑玉斷續丸", ({ "black jade pill","pill" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一顆黑色的小藥丸。\n");
		set("unit", "顆");
		set("value", 60);	//參考價格為回復點數總和除以5
		set("heal_hp",30);	//可以是"heal_hp"或是"heal_mp",
		set("heal_body",4);	//"heal_head" ,"heal_body"
		set("heal_head",4);	//"heal_hand" ,"heal_foot"也可以都有.
		//食用訊息 eat_msg 可以用 $N 表玩家, $n表此物.(房間都會看到)
		set("eat_msg","$N小心翼翼的從懷中拿出一顆$n, 放到口中吞了下去。");
		//效果訊息 eff_msg 不可用$N 及 $n (因為只有玩家會看到)
		set("eff_msg","你覺得身體狀態恢復了不少。");
	}
	setup();
}
