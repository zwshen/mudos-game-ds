#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "金波閣");
        set("long", NOR""+
"這是金波閣東側，角落堆滿了女人用的粉盒和鏡子，還有一些穿得\n"+
"很舊的衣物，一件一件掛在牆上，看來是整理過了。天花板上開了天窗\n"+
"，光線可以從上頭隱隱約約照進來。\n\n");

        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"r13",
]));
        set("objects",([
        __DIR__"npc/16" : 1,
]));
	setup();
}