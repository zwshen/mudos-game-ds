inherit ROOM;
void create()
{
	set("short", "森林");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_13",
	"east" : __DIR__"map_7_14",
	"north" : __DIR__"map_6_13",
	]));
	set("outdoors","forest");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

