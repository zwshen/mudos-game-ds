// 紫陽山第一層

inherit ROOM;

void create()
{
	set("short", "紫陽山");
	set("long", @LONG
你繼續往前走著走著，不時跑出幾塊突出的石壁，總是有些難以行
走，看起來這面山壁並不怎麼的平坦，往前走有一道小斜坡，可以繼續
往上爬。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"1f3.c",
  "southwest" : __DIR__"1f1.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
