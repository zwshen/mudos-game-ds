inherit ROOM;
void create()
{
	set("short", "森林外端");
	set("long",@LONG
這裡是步靈城南方的大森林的北邊，在這裡森林顯得更為茂盛，在
北邊是森林的出口，而在南方是往核心處的森林，這有些活躍的小動物
似乎在向你示威。
LONG
	);
	set("exits", ([
  "south" : __DIR__"forest3.c",
  "northeast" : __DIR__"forest.c",
]));
	set("outdoors","forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
