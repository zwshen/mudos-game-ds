// dumpling.c

inherit ITEM;
inherit F_PILL;

void create()
{
	set_name("黑玉斷續丸", ({ "black jade pill","pill" }) );
	set_weight(110);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
一顆黑色不起眼的小藥丸。
LONG
);
		set("unit", "顆");
		//食用訊息 eat_msg 可以用 $N 表玩家, $n表此物.(房間都會看到)
		set("eat_msg","$N小心翼翼的從懷中拿出一顆$n, 放到口中吞了下去。");
		//效果訊息 eff_msg 不可用$N 及 $n (因為只有玩家會看到)
		set("eff_msg","你覺得身體狀態恢復了不少。");
	}
	set("value", 1500);
	set("cure",([
		"body" : 8,
		"head" : 8,
		"right_arm" : 8,
		"left_arm" : 8,
		"right_leg" : 8,
		"left_leg" : 8,
	]));
	set("heal",([
		"hp" : 100,
		"mp" : 50,
		"ap" : 50,
	]));
	setup();
}
