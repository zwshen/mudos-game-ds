inherit ROOM;
void create()
{
	set("short", "道路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_31_25",
	"east" : __DIR__"map_31_27",
	]));
    set("objects", ([
        __DIR__"npc/obj/branche.c" : 1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

