inherit ROOM;
void create()
{
	set("short", "魚村石路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_8",
	"east" : __DIR__"map_3_10",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

