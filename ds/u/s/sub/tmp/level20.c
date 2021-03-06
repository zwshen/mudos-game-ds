#include <ansi.h>
inherit MOBROOM;
void create()
{
	set("short", "競技中級區");
	set("long", @LONG
這裡是競技場中一個小小的空地，不過卻十分的危險，因為這裡有
許多專門給冒險者練習閃躲、攻擊的大野獸，不過如果你不去動牠，牠
也不會來打你，正是所謂人不犯我，我不犯人之一般。
LONG
	);
	set("exits", ([
  "south" : __DIR__"hippodrome",
  "north" : __DIR__"level30",
]));
	set("no_clean_up", 0);
	set("chance",99);
	set("mob_amount",4);
	set("mob_object",({
  __DIR__"npc/fallenangel",
  __DIR__"npc/dog",
}));
	set("outdoors","land");
	set("light",1);
	setup();
}

int valid_leave(object me, string dir)
{
	string gender;
	gender=me->query("gender");
	if ( gender=="男性" ) gender="你";
	if ( gender=="女性" ) gender="妳";
	if ( me->query("age") > 50 ) gender="您";
	
	if( dir=="north" )
	{
		if(me->query("level")<20)
		{
			message_vision("在旁的武術家看到$N要進入危險的競技場，馬上上來喝止$N，\n"+"並對$N說：這位"+RANK_D->query_respect(me)+"，裡邊可是危險的很，請"+gender+"不要亂闖。\n", me);
			return notify_fail("那裡只有等級20以上才能進去。\n");
		}
	}
        return ::valid_leave(me, dir);
}