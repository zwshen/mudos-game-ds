inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_12",
	"south" : __DIR__"map_12_11",
	"north" : __DIR__"map_10_11",
	"west" : __DIR__"map_11_10",
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

