inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_27_43",
	"south" : __DIR__"map_28_44",
	"north" : __DIR__"map_26_44",
	"east" : __DIR__"map_27_45",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

