inherit ROOM;
void create()
{
	set("short", "巷道");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_15_28",
	"south" : __DIR__"map_16_27",
	"north" : __DIR__"map_14_27",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

