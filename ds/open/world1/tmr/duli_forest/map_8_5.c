inherit ROOM;
void create()
{
	set("short", "小路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_8_4",
	"south" : __DIR__"map_9_5",
	"east" : __DIR__"map_8_6",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

