// Room: /d/gumu/qinshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", HIC"琴室"NOR);
	set("long", @LONG
一張石桌(table)，一條石凳，桌上放著一把古琴，是小龍女休憩
時刻撫琴抒懷的地方。每每琴音裊裊，平淡清和，直引人心弛神往，與
世無爭。
LONG	);
	set("exits", ([
		"west" : __DIR__"mudao18",
	]));
	set("item_desc", ([
		"古琴"   : HIC"這是一把年代極遠的古琴，琴風古樸，暗蘊玄機。琴上刻著“至遠 寧心 渡風”六個字。\n"NOR,
		"table" : "桌上放著一把古琴。 \n",
	]));
	setup();
}

void init()
{
//	add_action("do_tan", "tan");
	add_action("do_tan", "play");
}

int do_tan(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

    return notify_fail("你必非古墓傳人，無法領悟古墓武功\。\n");

	c_skill=(int)me->query_skill("force", 1);
	c_exp=me->query("combat_exp");

	if (arg == "qin")
	{
		if(!(fam = me->query("family")) || fam["family_name"]!="古墓派")
    return notify_fail("你必非古墓傳人，無法領悟古墓武功\。\n");
		if (me->query("qi") < 30 || me->query("jing") < 30)
			return notify_fail("你精神恍忽，先去歇息一會再來彈琴吧。\n");
		write(HIC"你閉目調理一會氣息，心神寧靜的撫琴而彈。\n"NOR);
		if (c_skill < 50 )
			return notify_fail("你彈了半天，琴聲仿若鴉鳴，你還是彈棉花去吧。\n");
		if (me->query_skill("force", 1) > 100)
		{
			message_vision(
HIC"$N心隨弦走，融入琴境，伴隨琴聲，高聲吟道：\n\n"
HIY"滄海一聲笑 滔滔兩岸潮\t浮沉隨浪 只記今朝
蒼天笑 紛紛世上潮\t誰負誰勝出 天知曉
江山笑 煙雨遙\t濤浪淘盡 紅塵俗世幾多嬌
清風笑 竟惹寂寥\t豪情還剩了一襟晚照
蒼生笑 不再寂寥\t豪情仍在 癡癡笑笑\n"NOR,me);
			return 1;
		}
		if( c_skill > 100)
            return notify_fail("你內功\精湛，彈琴已無益于你修行內力。\n");
		write("你心隨弦走，融入琴境，漸漸心氣平和，周身真氣自然流動。\n");
		me->receive_damage("qi", 15+random(10), me);
		me->receive_damage("jing", 15+random(10), me);
		if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("force", random(me->query("int")) );
		return 1;
	}
    write("你要彈什麼？\n");
	return 1;
}

