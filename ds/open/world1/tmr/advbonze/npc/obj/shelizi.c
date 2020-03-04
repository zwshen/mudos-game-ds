// 舍利子 shelizi.c

#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("七色舍利子", ({ "shelizi pill","pill" }));
        set("long",@LONG
一顆散發著七彩光芒的舍利子，約有雞蛋般大小，渾圓剔透，外表光
滑無瑕玼，握在手裡即感覺到難以言喻的奇妙感應，仿以一剎那頓悟通明
，求法得法。
LONG
	);
        set_weight(50);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
	        set("unit", "顆");
		set("eat_msg",HIC"$N吃下一顆散發七彩光芒的藥丸。"NOR);
	        set("eff_msg",HIY "一陣慈詳的光芒開始籠罩著你，耳畔響起一陣佛號....\n" 
						+ NOR CYN "(你身上的傷勢都恢復了！！)" NOR );
	}
	set("value", 5000);
	set("cure",([
		"body" : 50,
		"head" : 50,
		"left_leg" : 10,
		"right_leg" : 10,
		"left_arm" : 10,
		"right_arm" : 10,
	]));
	set("heal",([
		"hp"	: 300,
		"mp"	: 300,
		"ap"	: 300,
	]));
    setup();
}
