inherit ROOM;
void create()
{
	set("short", "田地");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_10",
	"south" : __DIR__"map_12_9",
	"north" : __DIR__"map_10_9",
	"west" : __DIR__"map_11_8",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

