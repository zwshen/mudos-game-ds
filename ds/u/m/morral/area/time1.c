#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIR"光陰的殿堂"NOR);
set("long",@LONG
這裡是時間與空間的裂縫，在這裡已經不能再回頭，
而通往未來的道路就在前方，這裡有著一個小小的精靈，
大大的綠色眼睛看著你，好像想對你講些什麼。

LONG);
set("exits",([
"north":__DIR__"time2",
"west":__DIR__"trans",
]));
set("light",1);
set("objects",([
__DIR__"npc/mili" : 1]));
set("no_clean_up",0);
setup();
replace_program(ROOM);
}
