inherit ROOM;
void create()
{
	set("short", "地下大墳場-大廳");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_12_12",
	"west" : __DIR__"map_13_11",
	"east" : __DIR__"map_13_13",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

