// Room: /d/gumu/qianliu2.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"潛流"NOR);
	set("long", @LONG
你沒在水中，只覺水勢甚急，沖得你無法立足。你氣悶異常，只得屏氣摸
索潛行，當真是進退維谷。
LONG	);

	set("exits", ([
		"west"   : __DIR__"qianliu1",
		"eastup" : __DIR__"anhe2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
