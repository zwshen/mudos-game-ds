inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_2_16",
	"west" : __DIR__"map_3_15",
	"south" : __DIR__"map_4_16",
	"east" : __DIR__"map_3_17",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

