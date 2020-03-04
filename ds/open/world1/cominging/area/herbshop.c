inherit ROOM;
void create()
{
	set("short", "清香藥舖");
	set("long",@LONG
這是步靈城中一家不太有名的小藥舖，不過在這裡卻麻雀雖小，五
臟俱全，只要你想得出來的中藥都買得到，在南方是步靈城中的西大街
，在外頭還有些許的客人前往這裡，舖裡的店舖老板忙的不亦樂乎，好
像忙的很快樂，大概是因為來買的人突然變多，也似乎有著一絲絲的憂
愁的樣子。
LONG
	);
	set("exits", ([
  "south" : __DIR__"bwest1.c",
]));
	set("objects",([
  __DIR__"npc/herbalist.c": 1,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}