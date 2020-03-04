inherit ROOM;
void create()
{
	set("short", "庭院");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_16_32",
	"north" : __DIR__"map_14_32",
	"west" : __DIR__"map_15_31",
	]));
	set("objects", ([
	__DIR__"../npc/beast_dog_5" : 1,
	]) );
  	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

