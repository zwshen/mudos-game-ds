// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"席拉的家"NOR);
	set("long", @LONG
這間家具擺飾陳放得井然有序的民房是席拉的住所，雖然這是她的家
，但是卻不常看到席拉本人；相反的卻常常看到不明人士在這裡流連。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room084",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}