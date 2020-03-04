inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_21_8",
	"south" : __DIR__"map_22_7",
	"north" : __DIR__"map_20_7",
	]));
        set("objects",([
                __DIR__"npc/corpse.c" : 2 ,
                __DIR__"npc/corpse2.c" : 2 ,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

