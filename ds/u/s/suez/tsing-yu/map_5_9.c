inherit ROOM;
void create()
{
	set("short", "民房");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_10",
	"south" : __DIR__"map_6_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

