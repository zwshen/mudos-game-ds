inherit ROOM;
void create()
{
	set("short", "廚房");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_34",
	"north" : __DIR__"map_11_33",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

