#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "步靈城北門");
	set("long",
"\n"
"◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣\n"
"██　　██　　██　　██　　██　　██　　██　　██\n"
HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"███"HIB"※步靈城北門※"HIR"██"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"███▇"HIR"▇▇▇▇"HIW"▇▇██"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"██"HIY"Ω"HIR"█"HIW"　　　　"HIR"　█"HIY"Ω""█"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"██"HIY"Ω"HIW"█"HIR"　　　　"HIW"　█"HIY"Ω""█"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"██"HIY"Ω"HIR"█"HIW"　　　　"HIR"　█"HIY"Ω""█"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"██"HIY"Ω"HIW"█"HIR"　　　　"HIW"　█"HIY"Ω""█"HIR"████"HIW"████"HIR"██\n"
HIR"◥███"HIW"████"HIR"████"HIW"　　　　"HIR"　███"HIW"████"HIR"████"HIW"█◤\n\n"NOR
	);
	set("exits", ([
  "out" : __DIR__"river4.c",
  "south" : __DIR__"bnorth6.c",

]));
	set("objects",([
  __DIR__"npc/gateguard.c": 3,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
        if( dir== "out" && !userp(me))
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me,dir);
}
