inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_27_12",
	"south" : __DIR__"map_28_13",
	"north" : __DIR__"map_26_13",
	"east" : __DIR__"map_27_14",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

