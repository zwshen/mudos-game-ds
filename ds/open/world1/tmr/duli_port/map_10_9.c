inherit ROOM;
void create()
{
	set("short", "中央廣場");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_9",
	"east" : __DIR__"map_10_10",
	]));
        set("objects",([
                __DIR__"npc/fighter":2,
        ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

