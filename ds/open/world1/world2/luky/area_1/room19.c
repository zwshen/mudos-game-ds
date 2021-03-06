// Modify with AreaMaker1.0
// Room19.c

inherit ROOM;

void create()
{
	set("short","樹林");
	set("long", @LONG
強大的風不斷的從東北邊吹來，狂風使你很難睜開眼睛看清楚這
裡有些什麼東西。砂石如子彈般打在你的皮膚上讓你疼痛難耐。
LONG
	);
	set("exits", ([
		"north": __DIR__"room9",
		"east": __DIR__"room20",
		"south": __DIR__"room29",
		"west": __DIR__"room18",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir=="east" || dir=="north" )
		return notify_fail("那裡的風太強了以至於你無法走過去。\n");
	return ::valid_leave(me, dir);
}
