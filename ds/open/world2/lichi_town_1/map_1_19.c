inherit ROOM;
void create()
{
	set("short", "梅龍鎮");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_1_20",
	"south" : __DIR__"map_2_19",
	"north" : __DIR__"map_0_19",
	"west" : __DIR__"map_1_18",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

