inherit ROOM;
void create()
{
	set("short", "¶À±ö¤½¶é");
        set("long", @LONG
          [1;33m³o¸Ì¦³´Ê«D±`¤jªº¾ð¡A»P¨ä¥Lªº¾ð¦³¨Ç¤£¦P¡C[0m
LONG
);
	set("item_desc",([	
	"tree" : "³oÁû¾ð¤Q¤À¥¨¤j¡A¦ü¥G¨Ã¤£Ãøª¦(climb)¡C\n",
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
	if(!arg) return notify_fail("§A·Qª¦¤°»ò¡H\n");
	if(me->is_busy()) return notify_fail("§A¤W¤@­Ó°Ê§@ÁÙ¨S§¹¦¨¡C\n");
	if(arg=="tree" || arg=="¾ð" || arg == "¤j¾ð")
	{
		message_vision("$N¤p¤ßÁlÁlªºª¦¤W¤F¤j¾ð¡C\n",me);
		me->move("/open/world2/lichi_town_2/map_12_2");
		tell_room(environment(me),me->name()+"ª¦¤F¤W¨Ó¡C\n",({me}));
		return 1;
	}
	else return notify_fail("³o¸Ì¨S¦³³o­ÓªF¦è¥iª¦¡C\n");
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

