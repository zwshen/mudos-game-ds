// Room: /u/s/superbug/train/8.c

inherit ROOM;

void create()
{
	set("short", "地下鐵入口");
	set("long", @LONG
這裡是通往地下鐵的入口，樓梯上散落著垃圾和吃完的食物，看起來
已經有一陣子沒人來打掃了，在旁邊還有幾個流浪漢正看著你，你頓時覺
得自己與這裡格格不入，想要快點逃開。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"a-9.c",
  "south" : __DIR__"a-13.c",
  "north" : __DIR__"a-1.c",
  "east" : __DIR__"a-5.c",
  "climbdown" : __DIR__"1.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
