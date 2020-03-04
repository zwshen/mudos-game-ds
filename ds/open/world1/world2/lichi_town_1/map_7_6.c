inherit ROOM;
void create()
{
	set("short", "民宅門口");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_6_6",
    "south" : "/open/world2/lichi_town_2/map_8_6",
	]));
	set("objects",([
		__DIR__"../npc/malo_oldlady_9":1,
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

