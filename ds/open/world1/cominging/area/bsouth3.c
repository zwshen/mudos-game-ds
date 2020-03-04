inherit ROOM;
void create()
{
	set("short", "步靈城南大街南");
	set("long",@LONG
你正站在步靈城中南大街南邊的路上，在這裡比北邊要蕭條許多，
也沒有像北邊如此多的店家，不過這裡卻有一家名聞遐邇的競技場，在
那的外邊有許多等著進入挑戰的冒險者，便如一條長龍一般延伸到街的
尾端。
LONG
	);
	set("exits", ([
  "north" : __DIR__"bsouth2.c",
  "east"  : __DIR__"hippodrome.c",
  "south" : __DIR__"bsouth4.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}