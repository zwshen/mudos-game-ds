// forestroom.c

inherit ROOM;

void create()
{
	set("short", "古代的世界(森林)");
	set("long",@LONG
這裡是藍藍的天測試用的房間，歡迎參觀。你可以 more here  以觀察
這個房間的寫法。歡迎你加入夢幻七域的行列，再次提醒你，在你盡情寫作
的同時，希望你能夠遵守這裡的相關規定！祝你  幸福快樂。
LONG
	);
	set("exits", ([
		"east" : __DIR__"snowroom",
		"west" : __DIR__"landroom",
	]) );

	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}