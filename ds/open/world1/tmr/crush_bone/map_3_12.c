inherit ROOM;
void create()
{
	set("short", "石板橋");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_12",
	"north" : __DIR__"map_2_12",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

