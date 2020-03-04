// 而瓆吹

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"懂产皊┍"NOR);
	set("long", @LONG
程Τ皊常琌硂艭硑Τ砛常琌环眖紏τㄓ
Τ秸皊畍タ秸籹綣皊鲤Τボ礟(sign)
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room068",
	    "down" : __DIR__"room106",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss3" : 1,
	]));
        set("item_desc", (["sign":@NOTE

礟糶帝:  皊綤ぃ秨ó秨óぃ耻皊

	==========================
	都珇睲虫	list
	潦禦都珇	buy <都珇>
	==========================

NOTE
        ]) );

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

