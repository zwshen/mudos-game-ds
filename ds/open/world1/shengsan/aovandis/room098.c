// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"戰士訓練場"NOR);
	set("long", @LONG
這裡是戰士們練習技能的場所，有位戰士導師在這裡認真的教導他的
學生。四周不時傳出戰士們操練時所發出的打鬥吶喊聲，威武的叫聲讓你
覺得奧凡迪斯是個打不倒的城市。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room086",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}