inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_2",
	"south" : __DIR__"map_10_3",
	"east" : __DIR__"map_9_4",
	"north" : __DIR__"map_8_3",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

