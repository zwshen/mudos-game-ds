inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_11",
	"east" : __DIR__"map_10_12",
	"north" : __DIR__"map_9_11",
	"west" : __DIR__"map_10_10",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

