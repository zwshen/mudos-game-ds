// Room: /u/s/sub/area/village/inn.c

inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
這裡是陳老婆婆的家裡，屋內的陳設相當的素雅簡單，可以看出她是
一位相當有品味的人。如果累了或者肚子餓了可以來這邊喔﹗陳老婆婆會
很熱心的招待你的。不過天下沒有白吃的午餐，當然要給她一些些的金錢
當作是謝禮。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"vi04",
]));
	set("current_light", 4);
	set("world", "undefine");
	set("light", "1");
	set("room_type", "food");
	set("valid_startroom", "1");
    set("objects", ([
    __DIR__"npc/village_waiter_5" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
