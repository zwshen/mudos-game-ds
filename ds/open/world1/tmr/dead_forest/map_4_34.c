inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_35",
	"south" : __DIR__"map_5_34",
	"west" : __DIR__"map_4_33",
	]));
    set("objects", ([
          "/adm/active/jason.c": 1,
          "/obj/statue": 1,
    ]));
          set("no_fight",1);
        set("no_clear",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

