// Room: /u/f/fanny/area/town2.c

inherit ROOM;

void create()
{
	set("short", "村口");
	set("long", @LONG
往西直走，慢慢的進入了村莊裡。左右兩排的桃樹提供村裡老老
少少休閒的地方，北邊是有名的『留步客棧』，據聞店名是前朝太子
所賜的。
    再往西直走就是人來人往的大街了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"town3",
  "north" : __DIR__"towninn1f.c",
  "east" : __DIR__"town1",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/u/f/fanny/area/npc/villager" : 2,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
