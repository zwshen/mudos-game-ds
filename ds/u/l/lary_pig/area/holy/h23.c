#include "path.h"
inherit ROOM;

void create()
{
        set("short", "水瓶宮");
        set("long", @LONG
黃道十二宮的第十一宮 ─ 水瓶宮，走進這裡，你感到十分的奇
怪，在此宮殿裡，一反常態的，居然沒有任何一名守護者在看守；在
宮殿的中央，有一個小水池，而水池的中央，有一個有持水瓶的雕像
，在水池的後方，便是宮殿的出口。
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h24",
 "west" : HOLY+"h22",
        ]) );
        set("light",1);
        setup();
}
