inherit ROOM;
void create()
{
	set("short", "岩漿");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_3",
	"east" : __DIR__"map_4_4",
	"north" : __DIR__"map_3_3",
	"west" : __DIR__"map_4_2",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

