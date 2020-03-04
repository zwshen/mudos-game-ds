inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
這裡是一條長走道，你在走道的“邊疆”地帶，有些地方放有花卉
樹木，有些守衛倚靠門邊而鼾鼾打盹。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"path3",
  "west" : __DIR__"house3",
  "south" : __DIR__"path5",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
