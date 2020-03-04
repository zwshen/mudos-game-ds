#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",BLU"燈塔一樓"NOR);
        set("long",@LONG
空曠的空間，微微的光芒從入口以及石縫中滲了進來，一道道光的通
路灑向塔內的各個角落。一種奇異又神秘的感覺，讓你不禁呆立在這裡。
在正中央的地方，有一座巨大的石梯通往二樓。
LONG 
);      
        set("light",0);
        set("exits",([
            "up":__DIR__"port_a2",
	    "out":__DIR__"port_00"
                ]));
        set("world","world1");
        set("objects",([
             __DIR__"npc/bat":5,
                ]));

        setup();
        replace_program(ROOM);

}

