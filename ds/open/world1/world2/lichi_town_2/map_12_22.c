inherit ROOM;
void create()
{
	set("short", "酒吧");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_23",
	"south" : __DIR__"map_13_22",
	"north" : __DIR__"map_11_22",
	]));
	set("light",1);
	set("objects",([
	__DIR__"../npc/malo_spock_18":1,
	]));
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

