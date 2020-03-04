// Room: /u/d/darkfool/area1/17.c

inherit ROOM;

void create()
{
	set("short", "北住宅區街道");
	set("long", @LONG
這裡北面有一幢大房子，那是HANS轄下礦業公司派來負責此地礦
場事務的負責人辦事處兼住家，銀白的門口浮印上了斗大的HANS標誌
，看來頗有魄力。你在想裡面住的不知道會不會是個難纏的傢伙。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"16",
]));

	setup();
	replace_program(ROOM);
}
