inherit ROOM;
void create()
{
	set("short", "旅館大廳");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_27",
	"north" : __DIR__"map_3_27",
	"west" : __DIR__"map_4_26",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
}

int valid_leave(object me, string dir)
{
	if( dir=="north" )
	{ 
                if(!me->query_temp("malo/inn") ) 
	{
	tell_object(me,"當你走近房門時，兩旁突然伸出許\多柵欄擋住了你的去路。\n大廳裡突然傳來旅館小姐的聲音：這位顧客請先來櫃檯訂房。\n");
		return notify_fail("");
	
}
                if(this_object()->query("full")) 
	{
tell_object(me,"當你走近房門時，發現裡面已經有人了，你只好等一等了。\n");
		return notify_fail("");
}
// edit by alick
	}
	return ::valid_leave(me, dir);
}
