inherit ROOM;

void create()
{
	set("short", "村長家");
	set("long", @LONG
這裡就是伏克村的村長海頓的房子，這間房子雖然不是很豪華，
但是跟周圍的房子一比，就顯得略為高大，而且特別的是還有樓梯可
以通往二樓。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  		"up" : __DIR__"house1f2",
  		"south" : __DIR__"burg2",
	]));
	set("objects",([
		__DIR__"npc/haydn.c":1,
	]));

	setup();
	replace_program(ROOM);
}
