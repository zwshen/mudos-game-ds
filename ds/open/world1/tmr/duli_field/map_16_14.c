inherit ROOM;
void create()
{
	set("short", "廢棄的石路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_16_13",
	"north" : __DIR__"map_15_14",
	"east" : __DIR__"map_16_15",
	"south" : __DIR__"map_17_14",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

