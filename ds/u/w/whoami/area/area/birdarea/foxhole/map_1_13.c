inherit ROOM;
void create()
{
        set("short", "狐穴");
        set("long", @LONG

LONG
);
        set("exits",([ 
        "northeast" : __DIR__"map_0_14", 
        "northwest" : __DIR__"map_0_12",
        "southeast" : __DIR__"map_2_14",
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

