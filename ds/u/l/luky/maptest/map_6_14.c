inherit ROOM;
void create()
{
        set("short", "�Ŧa");
        set("long", @LONG
�o�̬O�@���|���}�o���Ŧa�C

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_13",
	"south" : __DIR__"map_7_14",
	"north" : __DIR__"map_5_14",
	"east" : __DIR__"map_6_15",
	]));
        set("out_doors","land");
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}
