inherit ROOM;
void create()
{
	set("short", "寒日洞二層");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_5",
	"east" : __DIR__"map_6_7",
	"south" : __DIR__"map_7_6",
	"north" : __DIR__"map_5_6",
	]));
        set("objects",([
                __DIR__"npc/madman":1,
        ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

