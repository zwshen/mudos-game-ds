inherit ROOM;
void create()
{
	set("short", "榕樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_9",
	"west" : __DIR__"map_2_7",
	"south" : __DIR__"map_3_8",
	"north" : __DIR__"map_1_8",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

