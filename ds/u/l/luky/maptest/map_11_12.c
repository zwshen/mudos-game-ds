inherit ROOM;
void create()
{
        set("short", "�Ŧa");
        set("long", @LONG
�o�̬O�@���|���}�o���Ŧa�C

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_11",
	"north" : __DIR__"map_10_12",
	"east" : __DIR__"map_11_13",
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
