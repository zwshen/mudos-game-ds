inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_20",
	"west" : __DIR__"map_2_18",
	"south" : __DIR__"map_3_19",
	"north" : __DIR__"map_1_19",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

