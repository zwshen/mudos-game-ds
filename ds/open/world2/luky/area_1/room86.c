// Modify with AreaMaker1.0
// Room86.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在一片樹林中。地上的雜草長得十分茂盛。你隱約看到不
遠的西方有一座湖，南邊則是茂密的灌木林。
LONG
	);
	set("exits", ([
		"east": __DIR__"room87",
		"west": __DIR__"room85",
		"northwest": __DIR__"room75",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

