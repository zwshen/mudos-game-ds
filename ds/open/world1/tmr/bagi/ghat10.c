// Room: /open/world1/tmr/bagi/ghat10.c

inherit ROOM;

void create()
{
	set("short", "林道");
	set("long", @LONG
寒冽的風勢呼嘯般的穿梭在林木之中，銀白色的雪地反射著刺眼的陽
光，體質稍弱的人早就抵擋不住這種嚴酷的環境。不停下著的雪遮蔽了行
人的視線，但仍然勉強可以看到林道彎向西北角後就斷了，取而代之的就
是一處林地。
LONG
	);
	set("outdoors", "snow");
	set("current_light", 4);
	set("no_clean_up", 0);
	set("world", "past");
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"ghat11",
  "southeast" : __DIR__"ghat5",
]));

	setup();
	replace_program(ROOM);
}
