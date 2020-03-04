inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
你來到了走道接往公堂的地方，往北邊你彷彿看的見縣太爺那嚴肅
的眼神正盯著你看，感覺到一股寒顫，往南邊是一間間的房間和小舍子
。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"path7",
  "west" : __DIR__"path4",
  "north" : __DIR__"hall",
  "south" : __DIR__"path2",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
