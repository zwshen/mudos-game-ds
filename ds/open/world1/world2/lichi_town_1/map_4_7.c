inherit ROOM;
void create()
{
	set("short", "小廣場");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_8",
	"south" : __DIR__"map_5_7",
	"west" : __DIR__"map_4_6",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

