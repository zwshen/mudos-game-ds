// Room: /u/a/acme/area2/t32.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下四層]");
	set("long", @LONG
你正走在這陰暗的地道，你慢慢發覺地上濕泠泠的，似乎越往裡
頭地面越濕，這裡的空氣也越來越難聞，五味雜陳，令人作嘔。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"t33",
  "northeast" : __DIR__"t31",
]));
         set("objects",([
            __DIR__"npc/fate" : 1,
         ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

