inherit ROOM;
void create()
{
	set("short", "林中小路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_17_10",
	"north" : __DIR__"map_15_10",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

