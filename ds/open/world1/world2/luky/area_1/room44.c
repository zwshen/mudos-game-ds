// Modify with AreaMaker1.0
// Room44.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
你正走在樹林中。北邊有一棵似乎十分古老的大樹，你這輩子從
未見過如此粗大的樹。樹旁有個木樁，似乎原先是個路標，但是現在
只剩下了木樁固定在地上。
LONG
	);
	set("exits", ([
		"east": __DIR__"room45",
		"west": __DIR__"room43",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

