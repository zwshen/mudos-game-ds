inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
這裡有一間間的房間，在你的附近似乎有些大官的住處，所以常常有
一些官兵在巡邏察視。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"path1",
  "west" : __DIR__"house1",
  "north" : __DIR__"path5",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
