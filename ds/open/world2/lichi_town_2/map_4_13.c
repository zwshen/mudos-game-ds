inherit ROOM;
void create()
{
	set("short", "武器店");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_14",
	"north" : __DIR__"map_3_13",
	"west" : __DIR__"map_4_12",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

