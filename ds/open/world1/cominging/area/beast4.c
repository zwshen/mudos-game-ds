inherit MOBROOM;
void create()
{
	set("short", "步靈城東邊小路");
	set("long",@LONG
你站在步靈城東邊的大街旁的一條小路上，這裡顯得比剛剛還要安
靜得多了，東邊是步靈城的大門，而西邊則是往中央廣場前進，這裡有
一些些的建築物，但卻都不怎麼高，在那附近有一些給人方便的茅廁之
類的公用區。
LONG
	);
	set("exits", ([
  "west" : __DIR__"beast3.c",
  "east" : __DIR__"beast5.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",35);
        set("mob_amount",3);
	set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}