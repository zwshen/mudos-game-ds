inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_5",
	"south" : __DIR__"map_10_4",
	"north" : __DIR__"map_8_4",
	"west" : __DIR__"map_9_3",
	]));
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

