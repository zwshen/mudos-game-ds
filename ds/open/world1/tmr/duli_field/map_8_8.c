inherit ROOM;
void create()
{
	set("short", "岩穴入口");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_7_8",
	"south" : __DIR__"map_9_8",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

