inherit ROOM;
void create()
{
	set("short", "防具店");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_17_28",
	]));
    set("objects", ([
        __DIR__"npc/pi.c" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

