inherit ROOM;
void create()
{
	set("short", "寒日洞三層");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_1",
	"north" : __DIR__"map_5_1",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

