// Room: /d/gumu/jingxiu.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short",HIC"石室"NOR);
	set("long", @LONG
此地供各弟子打坐靜修之用。地上僅有幾個蒲團，幾個古墓弟子正
在閉目領悟。正面的石��(wall)上刻著不少文字, 仔細一看，原來都抄
錄著四書五經等古籍，用來給古墓弟子提高修養。
LONG	);

	set("exits", ([
		"south" : __DIR__"mudao21",
	]));
	set("item_desc", ([
		"wall" : "�暀W寫滿了各種古籍文字。\n",
	]));
	setup();
}

void init()
{ 
	::init();
	add_action("do_think", "think");
	add_action("do_think", "lingwu");
}

int do_think(string arg)
{
	mapping fam;
	object me = this_player();

	if ( !living(me) ) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙著哪！\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
          return notify_fail("你不是古墓傳人，無法領悟古墓武功\。\n");
	if (arg == "qiang" || arg == "wall")
	{
		if ((int)me->query("jing") < 20 )
			return notify_fail("你覺得好累,好想睡覺。\n");
		if ( me->query_skill("literate", 1) > 140)
			return notify_fail("你已經完全讀懂了�暀W的文字。\n");
		if ( me->query_skill("literate", 1) > 10 &&
			me->query_skill("literate", 1) > me->query("combat_exp")/1000)
			return notify_fail("你的經驗不夠，不能讀懂�暀W的文字。\n");
		if (me->query("potential", 1) - me->query("learned_points") < 1)
			return notify_fail("你沒潛能了，不能再繼續修習了。\n");
		me->add("learned_points", 1);
		me->receive_damage("jing", 5 + random(10));
		me->improve_skill("literate", random(me->query_int()));
		write("你對著石壁，仿佛有所領悟。\n");
		return 1;
	}
      return notify_fail("你想要領悟什麼？\n");
}

