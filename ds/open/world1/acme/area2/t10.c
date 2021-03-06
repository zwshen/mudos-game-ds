// Room: /u/a/acme/area2/t10.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下一層]");
	set("long", @LONG
這裡是幽冥地窖的地下一層，四周昏暗不明，殺氣騰騰，在你身旁射來一
道冷冷的眼光，令你感到無比的壓力，不知是否繼續往前行。在你眼前隱約能
看見有左右二排的大石柱，石柱圍成一個圓圈，在石柱中央有個往下的階梯。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"t9",
  "eastdown" : __DIR__"t11",
]));
        set("objects",([
         __DIR__"npc/wu" : 1,
       ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="eastdown" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
        return ::valid_leave(me, dir);
}
