inherit ROOM;
void create()
{
	set("short", "針葉林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_9_21",
	"north" : __DIR__"map_8_22",
	"east" : __DIR__"map_9_23",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

