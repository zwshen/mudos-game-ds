#include <room.h>
inherit BANK;
void create()
{
	set("short", "¿ú²ø");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_12_21",
	]));
        setup();
        set("map_long",1);     //show map as long
    replace_program(BANK);
}

