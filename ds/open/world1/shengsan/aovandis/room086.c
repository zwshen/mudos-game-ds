// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"戰士訓練場"NOR);
	set("long", @LONG
英勇的奧凡迪斯戰士都在這裡聚集訓練，他們是奧凡迪斯最勇敢的戰
士，嚴格的訓練使他們成為奧凡迪斯最強悍的一群勇者。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room098",
	    "south": __DIR__"room019",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}