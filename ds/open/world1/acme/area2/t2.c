// Room: /u/a/acme/area2/t2.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下一層]");
	set("long", @LONG
這裡是幽冥地窖的地下一層，四周昏暗不明，左右二側的牆壁上各有一排
的油燈座，但並無油可燃燒，此地瀰漫著一股土氣，惡臭難當，地上散亂著一
堆屍骨，卻不是人骨，而是動物的骸骨。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t3",
  "west" : __DIR__"t.c",
]));
     set("objects",([
        __DIR__"npc/dog" : 2,
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

