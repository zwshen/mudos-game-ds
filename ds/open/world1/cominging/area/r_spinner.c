inherit ROOM;
void create()
{
	set("short", "織布紡");
	set("long",@LONG
這裡是一家織布紡，這家織布紡的主人很年輕，聽說大約二十來歲
左右，不過手藝卻驚人的好，令人不禁翹起大拇指稱讚一番，在屋內有
滿箱的針以及各種質料的線，東邊是到往北街。
LONG
	);
	set("exits", ([
  "east" : __DIR__"bnorth4.c",
]));
	set("objects",([
  __DIR__"npc/spinner.c":1,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}