inherit ROOM;
void create()
{
	set("short", "客廳");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_14_35",
	"north" : __DIR__"map_13_34",
    "west" : "/open/world2/lichi_town_1/map_14_33",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

