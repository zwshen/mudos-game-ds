#include <ansi.h>
inherit ROOM;

void create()
{
 set("short", HIC"神風的家"NOR);
	set("long", @LONG
你看到一個很奇怪的房間，在牆上你發現很多紙張都寫有
「加油!努力!」的字句。 在你的東面是電腦室，你好像聽到笑聲
從電腦室傳出來，心想還是早點離開比較好。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "mulder" : "/u/m/mulder/workroom",
  "east" : __DIR__"workroom2",
"naboo" : "/u/m/mulder/area/naboo/middle",
]));
        set("objects",([
        "/u/s/sonicct/test/warrior.c":1,
        "/u/s/sonicct/test/berserk":1,
        "/u/s/sonicct/test/mage":1,
"/u/s/sonicct/test/Angel/seraphim":1,
        ]));

        set("valid_startroom", 1);
	set("no_clean_up", 0);
	setup();
        call_other("/obj/board/sonicct_b","???");
                replace_program(ROOM);
}
