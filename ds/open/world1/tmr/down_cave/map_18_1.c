inherit ROOM;
void create()
{
	set("short", "走道");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_17_1",
	"east" : __DIR__"map_18_2",
	]));
        set("objects",([
                __DIR__"npc/guard_monster2":1,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

