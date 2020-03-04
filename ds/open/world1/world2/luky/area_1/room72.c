// Modify with AreaMaker1.0
// Room72.c

inherit ROOM;

void create()
{
	set("short","湖畔");
	set("long", @LONG
這裡是依莉莎湖的東畔。東邊和北邊是一片樹林，湖邊有許多的
水草，還有一些水生的小動物。你看到湖邊的泥濘上有一些塑膠袋和
飲料罐，不知道是哪些可惡的傢伙亂丟的。
LONG
	);
	set("exits", ([
		"north": __DIR__"room62",
		"east": __DIR__"room73",
		"southeast": __DIR__"room83",
	]));
	 set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird0" : 1,
		__DIR__"npc/frog0" : 3,
	]));
	set("outdoors","land");		//戶外(平原)
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

