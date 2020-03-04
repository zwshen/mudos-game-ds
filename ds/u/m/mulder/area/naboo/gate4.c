// Room: /u/s/sonicct/area/gate4.c

inherit ROOM;

void create()
{
	set("short", "Naboo城門");
	set("long", @LONG
通過這道城門，就去到Naboo城最神秘的地方--叢林。那裡
只有一些勇敢的探險隊和研究人員會到那裡。人們最好就是離那
裡遠一點。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road12",
]));
		 set("objects",([
  __DIR__"npc/guard":1,
__DIR__"npc/guard1":2,
 ]));

	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="east" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}