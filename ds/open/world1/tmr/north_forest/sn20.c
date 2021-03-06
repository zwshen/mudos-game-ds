// Room: /open/world1/tmr/north_forest/sn20.c

inherit ROOM;

void create()
{
	set("short", "北方大森林-入口");
	set("long", @LONG
你眼前出現了一條筆直的小道直通往森林的深處，微風緩緩的吹來，腳
下的草地漸漸變成因許多人走過而踏平的泥地，泥地上還有許多因枯萎而掉
落變黃的樹葉，每走一步都會聽到與枯葉磨擦而生的沙沙聲，平添了一份恐
怖。
LONG
	);
	set("current_light", 4);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/rabbit" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/world1/faceoff/sky/ten18",
  "west" : __DIR__"sn19",
]));

	setup();
	replace_program(ROOM);
}
