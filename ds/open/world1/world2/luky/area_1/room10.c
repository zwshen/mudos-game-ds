// Modify with AreaMaker1.0
// Room10.c

inherit ROOM;

void create()
{
	set("short","碎石路");
	set("long", @LONG
走到這裡已經聽不到鳥獸的聲音了，東邊有一座大岩石擋住了去
路。北方不遠處似乎有座山脈。這裡到處都是小石頭，可能是附近的
巨岩風化崩落而成的吧。
LONG
	);
	set("exits", ([
		"south": __DIR__"room20",
		"west": __DIR__"room9",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

