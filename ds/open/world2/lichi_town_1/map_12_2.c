inherit ROOM;
void create()
{
	set("short", "黃梅公園");
        set("long", @LONG
          [1;33m這裡有棵非常大的樹，與其他的樹有些不同。[0m
LONG
);
	set("item_desc",([	
	"tree" : "這顆樹十分巨大，似乎並不難爬(climb)。\n",
	])	);
	set("exits",([
	"east" : __DIR__"map_12_3",
	"south" : __DIR__"map_13_2",
	"north" : __DIR__"map_11_2",
	"west" : __DIR__"map_12_1",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me;
	me=this_player();
	if(!arg) return notify_fail("你想爬什麼？\n");
	if(me->is_busy()) return notify_fail("你上一個動作還沒完成。\n");
	if(arg=="tree" || arg=="樹" || arg == "大樹")
	{
		message_vision("$N小心翼翼的爬上了大樹。\n",me);
		me->move("/open/world2/lichi_town_2/map_12_2");
		tell_room(environment(me),me->name()+"爬了上來。\n",({me}));
		return 1;
	}
	else return notify_fail("這裡沒有這個東西可爬。\n");
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

