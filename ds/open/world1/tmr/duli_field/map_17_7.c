inherit ROOM;
void create()
{
	set("short", "荒野草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_17_6",
	"north" : __DIR__"map_16_7",
	"east" : __DIR__"map_17_8",
	"south" : __DIR__"map_18_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

