#include <room.h>;
#include <ansi.h>;
inherit ROOM;
void create()
{
 set("short",HIC"NPC´ú¸Õ³B"NOR);


set("exits", ([
"east":__DIR__"workroom1.c",
]) );
set("objects",([
 __DIR__"origami/npc/master.c"   :1,
]));
set("light",1);
setup();
}
