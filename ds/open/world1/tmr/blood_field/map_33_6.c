inherit ROOM;
void create()
{
	set("short", "血跡");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_32_6",
	"west" : __DIR__"map_33_5",
	"south" : __DIR__"map_34_6",
	"east" : __DIR__"map_33_7",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

