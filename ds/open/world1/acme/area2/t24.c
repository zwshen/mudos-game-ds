// Room: /u/a/acme/area2/t24.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下三層]");
	set("long", @LONG
你正行走在這深不見低的黑暗地道，地道陰暗潮濕，令你渾身覺
得不舒服。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"t23",
  "east" : __DIR__"t25",
]));
	set("no_clean_up", 0);
	set("mob_object", ({ /* sizeof() == 1 */
   __DIR__"npc/ghost2.c",
}));
	set("mob_amount", 3);
	set("chance", 70);

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

