// dumpling.c

inherit ITEM;
inherit F_PILL;

void create()
{
	set_name("萬靈丹", ({ "cure pill","pill" }) );
	set_weight(330);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一顆藍色的小藥丸。\n");
		set("unit", "顆");
		set("value", 80);	//參考價格為回復點數總和除以5
		set("heal_hp",30);	//可以是"heal_hp"或是"heal_mp",
		set("heal_body",3);	//"heal_head" ,"heal_body"
		set("heal_head",3);	//"heal_hand" ,"heal_foot"也可以都有.
		set("heal_hand",2);	
		set("heal_foot",2);	
		//食用訊息 eat_msg 可以用 $N 表玩家, $n表此物.(房間都會看到)
		set("eat_msg","$N小心翼翼的從懷中拿出一顆$n, 放到口中吞了下去。");
		//效果訊息 eff_msg 不可用$N 及 $n (因為只有玩家會看到)
		set("eff_msg","你覺得身體狀態恢復了不少。");
	}
	setup();
}
