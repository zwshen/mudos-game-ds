#include "path.h"
inherit ROOM;

void create()
{
        set("short", "金牛宮");
        set("long", @LONG
黃道十二宮的第二宮 ─ 金牛宮，在這宮殿四周，刻畫著牛群角
逐對戰的景況，在這戰場後方的高臺上，豎立著一頭巨大，且金黃色
的公牛，正靜靜的觀看著比賽。
LONG
        );

        set("exits", ([
  "eastdown" : HOLY+"h4",
 "westup" : HOLY+"h6",
        ]) );
        set("light",1);
        setup();
}
