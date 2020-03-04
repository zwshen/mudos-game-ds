#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_giveup();
void heart_beat();

void create()
{
        set("short", "´ú¸Õ¤§¶¡");
        set("long", @LONG
This is test!!
LONG
        );
	set("objects",([
		__DIR__"laurel":10,
		__DIR__"mortar":3,
		__DIR__"pestle":3,
	]));
        setup();
}
