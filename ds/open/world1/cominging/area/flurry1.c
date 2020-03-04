inherit ROOM;

void create()
{
	set("short", "疾風門大門前");
	set("long", @LONG
這裡就是疾風門的，你一來到這裡就被這一片廣大的地所嚇一跳，
也不禁發出喔的一聲驚嘆聲，在門的旁邊都有很多衛兵，似乎閒雜人等
不太好進入的樣子。
LONG
	);
	set("exits", ([
  "south" : __DIR__"fgo9.c",
  "northwest" : __DIR__"flurry2.c",
]));
	set("objects",([
  __DIR__"npc/fseller.c":1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
