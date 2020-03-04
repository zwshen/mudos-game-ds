inherit MOBROOM;
void create()
{
	set("short", "北街末");
	set("long",@LONG
這裡是步靈城的北街末，一條長長的街就到此為止了，在北方是高
高的城牆和城門，在城門那有一些小販，似乎在販賣他所拿手做的東西
，南邊是往步靈城的中央，而北邊則是往城外走。
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth5.c",
  "north" : __DIR__"bdoor2.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",29);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}