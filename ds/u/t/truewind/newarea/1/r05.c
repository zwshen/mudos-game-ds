#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "香風閣");
        set("long", NOR""+
"這是二樓的香風閣裡香氣四溢，滿是胭脂水粉的味道，但是清淡\n"+
"不膩，令人神清氣爽。窗外看出去是熙熙攘攘的人群，攤販叫賣的聲\n"+
"音一清二楚。不過姑娘們的熱情款待還是使得客人變得十分熱情專注。\n\n");

        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"r08",
        "north" : __DIR__"r06",
        ]));
        set("objects",([
        __DIR__"obj/desk02" : 1,
        __DIR__"npc/08" : 1,
        __DIR__"npc/09" : 1,
]));
	setup();
}