#include "path.h"
inherit ROOM;

void create()
{
        set("short", "牡羊宮");
        set("long", @LONG
黃道十二宮的第一宮 ─ 牡羊宮，從這裡往天空望去，出神入化
的設計, 使你幾使在強烈的陽光照射下，也能清楚的看到牡羊座的變
化，使你不得不佩服古人的智慧。
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h2",
 "westup" : HOLY+"h4",
        ]) );
        set("light",1);
        setup();
}
