inherit ROOM;
#include <path.h>    

void create()
{
	set("short", "竹林步道");
	set("long", @LONG
這個步道看來有點陰森怪異，你可以聽到除了竹葉聲之外，還有夾
雜著斯斯的聲音，遇到這種情形，你也不由自主的提高警覺心，以應付
突來的狀況。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"room04",
            "south" :PUDON"cut_evil/room1",
	    "down" : __DIR__"room02",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
load_object("/u/p/pudon/war2/tfighter");
load_object("/u/p/pudon/war2/tiger");
	replace_program(ROOM);
}
