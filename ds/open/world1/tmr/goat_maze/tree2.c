// Room: /open/world1/tmr/goat_maze/tree2.c

inherit ROOM;

void create()
{
	set("short", "贛林樹洞");
	set("long", @LONG
你正爬在贛林老木的樹洞中，腳旁盡是腐臭的爛泥巴，還有幾十隻的
不知名毛蟲跟甲蟲，正在泥巴中鑽來鑽去，甚至還有幾隻爬到你的臉上跟
背上，搞的你心裡發毛。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/toad-king" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tree1",
]));
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
