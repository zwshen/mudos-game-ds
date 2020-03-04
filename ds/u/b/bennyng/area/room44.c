// Room: /u/b/bennyng/area/room44.c

inherit ROOM;

void create()
{
	set("short", "山羊宮前");
	set("long", @LONG
前面就是山羊宮，聽說山羊座聖鬥士是對雅典娜最忠成的一位，他的
聖劍可說是天下無雙，一掌可分天辟地，你心想前面的對手應小心對付．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"room45",
  "northup" : __DIR__"room41",
]));
        set("objects", ([
  __DIR__"npc/guard.c":4,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
