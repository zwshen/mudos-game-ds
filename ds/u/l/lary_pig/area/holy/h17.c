#include "path.h"
inherit ROOM;

void create()
{
        set("short", "天蠍宮");
        set("long", @LONG
黃道十二宮的第八宮 ─ 天蠍宮，在此宮四周的牆上，都有著古
人利用深紅色的顏料，所刻畫的赤蠍，在那群赤蠍的尾部，都鑲著一
顆散發出淡淡藍光的寶石，代表著，其尾針，含有強烈的劇毒！
LONG
        );

        set("exits", ([
  "eastup" : HOLY+"h18",
 "westdown" : HOLY+"h16",
        ]) );
        set("light",1);
        setup();
}
