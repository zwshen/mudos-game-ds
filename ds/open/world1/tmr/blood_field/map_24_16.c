inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_23_16",
	"west" : __DIR__"map_24_15",
	"south" : __DIR__"map_25_16",
	"east" : __DIR__"map_24_17",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

