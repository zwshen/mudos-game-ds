#include <ansi.h>
inherit ROOM;
void create()
{
set("short","山路");
 set("long", @LONG
你走在一條山路上，在你旁邊的是兩塊巨石，你位在中間的窄道上的階
梯上。灰色的巨石上攀附著幾條爬牆植物，可以見到一些大螞蟻在上面爬。
樹影在你的身旁搖晃著，遠處傳來奇怪的蟲鳴聲。
LONG
);
set("item_desc",([
]));

set("exits",([
  "southwest":__DIR__"m6",
  "northdown":__DIR__"m4",]));
 set("objects",([
      __DIR__"npc/mantisred" : 1,
 ]));
setup();
}


