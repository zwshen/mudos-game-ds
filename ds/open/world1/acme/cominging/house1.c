inherit ROOM;

void create()
{
	set("short", "工房");
	set("long", @LONG
這是一間工房，在這裡有許多的工人在這休息，這裡是工人休息以
及相關事項的地方，地上坐著一堆堆的工人，還有一些些的鐮刀，大概
是剛割完草回到這裡休息。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path6",
]));
	set("no_clean_up", 0);
	set("item_desc",([
  "鐮刀" : "一把看起來很沉重的刀，不過事實上卻不怎麼的重，大概是有些原因吧。\n",
]));
	set("objects",([
  __DIR__"npc/worker.c" :2,
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}
