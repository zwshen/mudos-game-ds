inherit ROOM;
void create()
{
	set("short", "黃梅公園");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_5",
	"south" : __DIR__"map_14_4",
	"north" : __DIR__"map_12_4",
	"west" : __DIR__"map_13_3",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

