// guild.c改自vendor.c

#include <path.h>
inherit ROOM;
inherit F_CLEAN_UP;
void create()
{
set("short","阿爾加斯暫存商店");
set("light",1);
set("objects",([
LUKY"pearl/npc/item/bag":3, //by luky
PUDON"item/torch":30,
LUKY"pearl/npc/item/fisharrow":60,

//"/mymud/torch1":1,//by pudon
]));
set("no_clean_up",1);
setup();
}
