inherit ROOM;
void create()
{
	set("short", "通道");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_14_10",
	"north" : __DIR__"map_12_10",
	]));
        set("objects", ([
        __DIR__"npc/hill_armyant_34" : 1,
        __DIR__"npc/hill_worker_20" : 2,        
        ]) ); 
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

