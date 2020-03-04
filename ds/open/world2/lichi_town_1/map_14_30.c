inherit ROOM;
void create()
{
	set("short", "庭院");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_14_31",
	"south" : __DIR__"map_15_30",
	"north" : __DIR__"map_13_30",
	"west" : __DIR__"map_14_29",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

