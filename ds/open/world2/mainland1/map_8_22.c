inherit ROOM;
void create()
{
	set("short", "針葉林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_8_21",
	"south" : __DIR__"map_9_22",
	"north" : __DIR__"map_7_22",
	"east" : __DIR__"map_8_23",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

