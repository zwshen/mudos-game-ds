// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"上層走道"NOR);
	set("long", @LONG
你站在一排排往北而上的石階之上，石階上鑲著各種炫麗的琉璃，所
排出的圖騰樣式讓人匪夷所思。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room052",
        "enter": __DIR__"room103",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
}

void init()
{
  this_player()->set_temp("now_old_city",1);
  this_player()->set_temp("now_new_city",0);
}
