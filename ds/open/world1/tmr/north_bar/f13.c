// Room: /open/world1/tmr/north_bar/f13.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-洞穴");
	set("long", @LONG
在這裡，野獸的吼叫聲傳遍四周，你感覺好像已經被野獸包
圍起來了。四周雖然黑暗，但好像有數對紅色的眼睛這在惡狠狠
的瞪視著你，讓你不禁開始毛毛的。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"f9",
  "northwest" : __DIR__"f16",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
