#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "比武場入口");
	set("long", @long
你走到這裡後發現這裡人山人海，原來這裡正是比武場的入口，
一堆堆想參加比武之人士正在搶著報名。另外，你也發現這裡有一塊
好高大的告示版豎立著。

	指令　:　[sign]　　　　　　參加比賽

long);
	set("light", 1);
	set("exits", ([
		"west" : "/open/world1/cominging/area/hippodrome",
	]));

	set("objects", ([
		__DIR__"obj/record" : 1,
	]));

	setup();
}

int start_game()
{
	object *obs;

	obs = all_inventory(this_object());

	foreach(object me in obs)
	{
		MATCH_D->enter(me);
	}

	return 1;
}
