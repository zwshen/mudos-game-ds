inherit ROOM;
void create()
{
	set("short", "通道");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_3_1",
	"south" : __DIR__"map_4_2",
	"east" : __DIR__"map_3_3",
	"north" : __DIR__"map_2_2",
	]));
        set("objects", ([
        __DIR__"npc/hill_radant_50" : 1,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

