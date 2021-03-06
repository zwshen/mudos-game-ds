// Room: /open/world1/tmr/north_bar/f20.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-洞穴");
	set("long", @LONG
在這裡，野獸的吼叫聲傳遍四周，你感覺好像已經被野獸包
圍起來了。四周雖然黑暗，但好像有數對紅色的眼睛這在惡狠狠
的瞪視著你，那你不禁開始毛毛的。
LONG
	);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dinosaur1.c" : 5,
  __DIR__"npc/dinosaur2.c" : 5,
  __DIR__"npc/dinosaur3.c" : 5,
  __DIR__"npc/mucus-odd.c" : 5,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"f19",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
