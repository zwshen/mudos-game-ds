inherit ROOM;

void create()
{
	set("short", "洞窟內");
	set("long", @LONG
你站在洞窟的中央，環顧四週，發現眼界恰好可以到達周圍的牆
壁，在看看腳底下，似乎有水流過的痕跡，你這才恍然大悟，原來這
裡是被地下河水長久時間沖刷所造成的結果。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gcave9",
  "east" : __DIR__"gcave12",
  "west" : __DIR__"gcave11",
  "south" : __DIR__"gcave13",
]));

	setup();
	replace_program(ROOM);
}
