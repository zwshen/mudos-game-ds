inherit ROOM;
void create()
{
	set("short", "葬屍江");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_8",
	"south" : __DIR__"map_5_8",
	"east" : __DIR__"map_4_9",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

