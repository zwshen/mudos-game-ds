//updated 26/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST。Road＠North"NOR);
    set("long", "來到這裡，你感到十分寧靜，令你感到非常舒暢。在這裡的中心，你
看到一個告示板，上面寫著《往北直通政府大樓》。南面便是市中心。\n");
 set("exits",([ 
"north":__DIR__"dst8.c",
"south":__DIR__"dmid.c",
]));
set("outdoors","land");
	setup();
	replace_program(ROOM);
}
