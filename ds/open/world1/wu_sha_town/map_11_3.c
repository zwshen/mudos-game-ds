inherit ROOM;
void create()
{
	set("short", "淺海");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_2",
	"north" : __DIR__"map_10_3",
	]));
        set("objects", ([__DIR__"../npc/eel" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

