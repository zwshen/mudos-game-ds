inherit ROOM;
void create()
{
	set("short", "石室");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_3_7",
	]));
        set("objects", ([
                __DIR__"npc/bandit" : 3,
                __DIR__"npc/bandit2" : 1,
        ]) );

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

