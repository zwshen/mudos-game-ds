inherit ROOM;
void create()
{
	set("short", "樓梯間");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_1_22",
	"up": __DIR__"tower2_1",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

