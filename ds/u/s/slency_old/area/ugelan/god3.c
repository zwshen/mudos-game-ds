// Room: /u/s/slency/area/ugelan/god3.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你現在位在羽聖雅教堂後方房舍的走廊上, 走廊邊種滿了花草, 一
片欣欣向榮向你襲了過來, 由此再往前走可以到達一些神父的房間, 遠
遠地你可以看見教堂後方的丘陵上有一片墓園。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"god9",
  "out" : __DIR__"god2",
  "east" : __DIR__"god4",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
