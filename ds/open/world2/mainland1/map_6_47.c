inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_46",
	"south" : __DIR__"map_7_47",
	"north" : __DIR__"map_5_47",
	"east" : __DIR__"map_6_48",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

