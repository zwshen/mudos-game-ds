inherit ROOM;
void create()
{
	set("short", "倉庫");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_33",
	"north" : __DIR__"map_3_33",
	"west" : __DIR__"map_4_32",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

