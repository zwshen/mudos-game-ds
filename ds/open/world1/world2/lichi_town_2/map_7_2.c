inherit ROOM;
void create()
{
	set("short", "客廳");
        set("long", @LONG

LONG
);
	set("exits",([
    "east" : "/open/world2/lichi_town_1/map_7_3",
	"south" : __DIR__"map_8_2",
	"north" : __DIR__"map_6_2",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

