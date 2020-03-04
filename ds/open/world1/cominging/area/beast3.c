inherit MOBROOM;
void create()
{
	set("short", "步靈城東大街東");
	set("long",@LONG
你慢慢的走到了這裡，步靈城中的東大街在這裡結束了，在南方有
一間屋子，在那周圍有許多前來參觀英雄之屋的人民或遊客，屋子周圍
有許多墳墓，可能是那位英雄所葬之地。
LONG
	);
	set("exits", ([
  "west" : __DIR__"beast2.c",
  "east" : __DIR__"beast4.c",
  "south" : __DIR__"herohouse.c",
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
