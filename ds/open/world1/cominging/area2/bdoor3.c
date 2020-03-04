#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "步靈城西門");
	set("long",
"\n"
"◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣\n"
"██　　██　　██　　██　　██　　██　　██　　██\n"
HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"███"HIC"《步靈城西門》"HIR"██"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"███▇"HIR"▇▇▇▇"HIW"▇▇██"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"██"HIY"◎"HIR"█"HIW"　　　　"HIR"　█"HIY"◎""█"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"██"HIY"◎"HIW"█"HIR"　　　　"HIW"　█"HIY"◎""█"HIR"████"HIW"████"HIR"██\n"
HIR"████"HIW"████"HIR"██"HIY"◎"HIR"█"HIW"　　　　"HIR"　█"HIY"◎""█"HIW"████"HIR"████"HIW"██\n"
HIW"████"HIR"████"HIW"██"HIY"◎"HIW"█"HIR"　　　　"HIW"　█"HIY"◎""█"HIR"████"HIW"████"HIR"██\n"
HIR"◥███"HIW"████"HIR"████"HIW"　　　　"HIR"　███"HIW"████"HIR"████"HIW"█◤\n\n"NOR
	);
	set("exits", ([
  "out" : __DIR__"river6.c",
  "east" : __DIR__"bwest5.c",
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