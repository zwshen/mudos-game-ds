inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_7",
	"east" : __DIR__"map_3_8",
	"north" : __DIR__"map_2_7",
	"west" : __DIR__"map_3_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

