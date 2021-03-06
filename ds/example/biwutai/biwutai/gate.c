// 山貓(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "比武場大門");
	set ("long", @LONG
這是小雪初晴比武場的大門，一座高高的木制牌坊，上書『比武場』
三個鎦金大字。這里經常舉辦各種類型的比武大會。所有的人都有機會參
加。
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"north"   : __DIR__"zoulang",
		"south"   : "/d/bianliang/guangming",
	]));
	set("objects", ([
		__DIR__"npc/gongping" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, where;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="north" ) {
		if(me->query("snowzongshi"))
			return ::valid_leave(me, dir);
		if( ob->query("fangshi")!="個人賽" && !ob->query("start/start"))
			return notify_fail("現在沒有任何比武，你不能進去。\n");
	}
	return ::valid_leave(me, dir);
}
