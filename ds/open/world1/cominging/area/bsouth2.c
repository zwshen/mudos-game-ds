inherit ROOM;
void create()
{
	set("short", "步靈城南大街中");
	set("long",@LONG
這兒是南大街的中央熱鬧之區，在這附近有許多碎石和許多動物的
排泄物，令人不禁想要趕快離開這裡，在大街的旁邊有一家豬舍，臭味
大概就是從那傳出來的吧，在北邊是步靈城南大街的北邊，有許多店家
而在往南一點就是南大街的南邊部分。
LONG
	);
	set("exits", ([
  "north" : __DIR__"bsouth1.c",
  "south" : __DIR__"bsouth3.c",
]));
	set("objects",([
  __DIR__"npc/traveller.c": 2,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
