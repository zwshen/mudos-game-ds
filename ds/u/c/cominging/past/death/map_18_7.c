inherit ROOM;
void create()
{
	set("short", "奈何橋");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_17_7",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

