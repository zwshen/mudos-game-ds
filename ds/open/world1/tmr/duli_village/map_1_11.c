inherit ROOM;
void create()
{
	set("short", "林路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_10",
	"east" : __DIR__"map_1_12",
	"south" : __DIR__"map_2_11",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

