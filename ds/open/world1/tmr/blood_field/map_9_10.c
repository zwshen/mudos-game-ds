inherit ROOM;
void create()
{
	set("short", "血跡");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_8_10",
	"west" : __DIR__"map_9_9",
	"south" : __DIR__"map_10_10",
	"east" : __DIR__"map_9_11",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

