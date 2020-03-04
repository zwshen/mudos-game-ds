inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
你漫步在走道上，對面也是一間間的房間，似乎這裡是一個大宿舍
？這裡有許多的通道，有些叫人眼花。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"path2",
  "west" : __DIR__"house2",
  "north" : __DIR__"path4",
  "south" : __DIR__"path6",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
