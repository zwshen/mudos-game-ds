inherit ROOM;
void create()
{
	set("short", "草原");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_12",
	"north" : __DIR__"map_3_13",
	"south" : __DIR__"map_5_13",
	"east" : __DIR__"map_4_14",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

