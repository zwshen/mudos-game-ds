#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "金波閣");
        set("long", NOR""+
"這裡是金波閣，看起來卻十分的樸素，只有靠窗的地方有幾張椅\n"+
"子，椅子亦十分老舊，鋪滿了灰塵。但是地上有一處明顯乾淨的地方\n"+
"，似乎有人經常在此走動。\n\n");

        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"r14",
        "down" : __DIR__"r12",
]));

	setup();
}