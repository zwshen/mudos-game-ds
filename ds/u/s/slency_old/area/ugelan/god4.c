// Room: /u/s/slency/area/ugelan/god4.c

inherit ROOM;

void create()
{
	set("short", "墓園入口");
	set("long", @LONG
這裡是一座墓園的入口, 往山丘上眺望, 一整片丘陵地上佈滿了墓
碑, 這附近的居民去世後都會埋葬在這片聖土中, 雖然說是墓園, 卻一
點也感受不到恐怖的氣氛, 一片詳雲反而讓你更加寧靜。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"god7",
  "south" : __DIR__"god6",
  "west" : __DIR__"god3",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
