inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_15_5",
	"west" : __DIR__"map_14_4",
	"north" : __DIR__"map_13_5",
	"east" : __DIR__"map_14_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

