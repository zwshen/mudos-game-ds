#include <room.h>
inherit ROOM;
void create()
{
 set("short","沼澤前");
 set("long",@LONG
你來到了一小片的沼澤之前, 這條小徑上都那麼潮濕應該就是
因為這個沼澤的關係了. 仔細看了看沼澤後方真的有一些光源在那
邊. 但是你得先通得過這片沼澤才行.
LONG
    );
 set("exits",([ "east":__DIR__"jungle7",
		"north":__DIR__"jungle9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}