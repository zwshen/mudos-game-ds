inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_9_24",
	"west" : __DIR__"map_10_23",
	"south" : __DIR__"map_11_24",
	"east" : __DIR__"map_10_25",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

