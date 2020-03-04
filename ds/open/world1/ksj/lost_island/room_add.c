#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","南無砂港泊口");
  set("long",@LONG
這裡是港口的南端，因為水淺沙高一般不會有船停靠，偶爾有幾
隻小魚穿梭在淺灘中，近來聽說有個外地人在這邊販賣奇特的物品，
還有一條能浮在海面的石舟，真得好好瞧瞧。
LONG
);
  set("exits", ([
      "north" : "/open/world1/wu_sha_town/seacoun42",
      "enter" : __DIR__"stone-boat",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/sailorman":1,
     ]) );
  setup();
}
