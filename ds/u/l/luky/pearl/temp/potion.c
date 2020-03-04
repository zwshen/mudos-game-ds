// guild.c§ï¦Ûvendor.c

#include <path.h>
inherit ROOM;
void create()
{
set("short","¼È¦sÃÄ©±");
set("light",1);
set("objects",([
LUKY+"pearl/npc/item/greenp":100,
LUKY+"pearl/npc/item/cacap":100,
]));
set("no_clean_up",1);
setup();
set("no_clean_up",1);
}
