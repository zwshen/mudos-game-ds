inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_13",
	"south" : __DIR__"map_3_14",
	"east" : __DIR__"map_2_15",
	"north" : __DIR__"map_1_14",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

