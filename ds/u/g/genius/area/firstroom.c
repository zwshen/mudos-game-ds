#include <room.h>
#include <ansi.h>
//從此格起進入area, 爾後使用相對路徑.

inherit ROOM;

void create()
{
set("short",HIB"愛門村"NOR);
 set("long", @LONG
這是一間密室，也是進入愛門村的神秘入口，屬於創世巫師群或是其
他神祇進入村莊的途徑。除了你進來的地方，你看不到任何其他的出口。

LONG
);
set("valid_startroom", 1);
set("light",1);

set("exits",([
   "area":__DIR__"al0",
   "out":"/u/g/genius/fightroom",]));
set("objects",([
     __DIR__"obj/eagle" : 1,
     "/u/g/genius/obj/cream" : 1,
     "/u/g/genius/obj/navel" : 1,
     "/u/g/genius/obj/coffee" : 1,
      ]));
setup();
}
