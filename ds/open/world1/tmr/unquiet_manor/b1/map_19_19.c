inherit ROOM;
void create()
{
	set("short", "幽暗地道");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_20_19",
	"west" : __DIR__"map_19_18",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

