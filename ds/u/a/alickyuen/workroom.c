#include <ansi.h>
#include <room.h>

inherit ROOM;

string *guest = ({ });
string *exits = ({
	"/d/wiz/hall1",
	"/u/c/cominging/workroom",
	"/u/b/baal/workroom",
});
string random_exit();

void create()
{
	set("short", HIR"Released Workroom "HIY"[Ver 1.0 beta]"NOR);
	set("long", @long
這是一個剛完成的工作站，是供各位巫師作樂用的房間，空閒時
也能來泡茶聊天，生活悠閒，簡直是巫師之中的聖地，聖地之中的天
堂。
long);
	set("exits", ([
//                "out" : (: random_exit :),
//                "out" : exits[random(sizeof(exits))],
		"qc" : __DIR__"qcroom",
		"enter" : __DIR__"programming",
		"test" : "/open/world1/alickyuen/match/entrance",
			"north" : "/u/t/tmr/workroom",
		"dd" : __DIR__"down_city/map_0_7",
	]));
	set("objects", ([
		__DIR__"killerjob" : 1,
		"/u/s/shengsan/npc/bluemaster" : 1,
		"/open/world1/acme/area/npc/fanny.c" : 1,
	]));
	set("valid_startroom", 1);

	setup();
	load_object("/obj/board/alickyuen_b");
}

void init()
{
}

string random_exit()
{
	return exits[random(sizeof(exits))];
}
