// Modify with AreaMaker1.0
// Room60.c

inherit ROOM;

void create()
{
	set("short","大草原");
	set("long", @LONG
這裡是一片大草原。這裡除了一大片的草地之外，沒有什麼特別
的東西。涼爽的微風從四周吹來，讓你覺得舒服的有點想睡覺。
LONG
	);
	set("exits", ([
		"south": __DIR__"room70",
		"west": __DIR__"room59",
		"northwest": __DIR__"room49",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");	
	setup();
	replace_program(ROOM);
}

