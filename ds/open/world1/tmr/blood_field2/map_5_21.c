inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_22",
	"west" : __DIR__"map_5_20",
	"south" : __DIR__"map_6_21",
	"north" : __DIR__"map_4_21",
	]));
		set("objects", ([
		__DIR__"npc/ents":2,
		__DIR__"npc/ents2":2,
		]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

