inherit MOBROOM;
void create()
{
	set("short", "階梯");
	set("long", @LONG
你正站在一個很寬的階梯上，階梯旁有許多樹木，大都是以楓樹為
主，所以在階梯上面會有一些掉落的楓葉，秋天時，在旁邊的棉花樹會
開出一盞盞美麗的花，賞心悅目。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"flurry43.c",
  "south" : __DIR__"flurry39.c",
  "east" : __DIR__"flurry45.c",
  "northup" : __DIR__"flurry46.c",
]));
	set("no_clean_up", 0);
	set("chance",40);
	set("mob_amount", 2);
	set("mob_object",({
  __DIR__"npc/apprentice",
}));
	set("outdoors","land");
	setup();
}
