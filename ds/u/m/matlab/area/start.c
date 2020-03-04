// Room: /u/m/matlab/area/start.c

inherit ROOM;

void create()
{
	set("short", "斷陽路");
	set("long", @LONG
眼前由於光線十分微弱，在搖晃不定的燭火裏你只能依稀地辨認出
這似乎是一座十分雄偉的殿堂，四周陳列著數十尊巨大的邪靈石像，在
光影擺動下更顯得陰森可怕，在略帶血腥味的空氣中隱隱傳來邪異的笑聲，
你心裏只想趕快離開這裏。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r1.c",
  "out" : __DIR__"entrance.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/2.c" : 4,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
