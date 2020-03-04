// Modify with AreaMaker1.0
// Room20.c

inherit ROOM;

void create()
{
	set("short","岩路");
	set("long", @LONG
狂風持續的吹著，你必須蹲低身體才能勉強站穩腳步。旁邊有一
些破舊的鐵網隨風搖擺，不斷發出尖銳刺耳的聲音。你要特別注意這
些�覂K網，要是突然被風吹斷打過來可是會出人命的。
LONG
	);
	set("exits", ([
		"north": __DIR__"room10",
		"south": __DIR__"room30",
		"west": __DIR__"room19",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

