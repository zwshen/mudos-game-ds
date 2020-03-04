inherit ROOM;
void create()
{
	set("short", "迷霧森林-小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_8",
	"east" : __DIR__"map_7_10",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/swordsman":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

