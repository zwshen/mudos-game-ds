inherit ROOM;
void create()
{
	set("short", "榕樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_18",
	"west" : __DIR__"map_10_16",
	"south" : __DIR__"map_11_17",
	"north" : __DIR__"map_9_17",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

