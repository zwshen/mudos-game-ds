// Room: /u/d/darkfool/area1/33.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
你走在這裡突然一陣涼風吹來，讓你有種不寒而慄的感覺，你望
了望四處，除了人比較少、房子也比較少之外，好像沒什麼特別之處
，或許是你太敏感了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"34",
  "west" : __DIR__"32",
]));

	setup();
	replace_program(ROOM);
}
