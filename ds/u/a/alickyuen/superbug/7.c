// Room: /u/s/superbug/train/7.c

inherit ROOM;

void create()
{
	set("short", "女廁所");
	set("long", @LONG
這裡是一間女廁所，意外地看起來十分乾淨，仔細一看似乎有人在清
掃的樣子，在牆角還有一堆紙箱和吃完的食物，看起來似乎有人在這逗留
的樣子，也許你可以找到某些線索。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"4.c",
]));
set("objects", ([
__DIR__"npc/child" : 1,
]));
        set("world", "future");
        set("light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
