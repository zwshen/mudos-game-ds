#include "path.h"
inherit ROOM;

void create()
{
        set("short", "雙魚宮");
        set("long", @LONG
雙魚宮，黃道十二宮的最後一宮，同時，也是你這趟冒險的最終
站，在你的前方，站立著一位身材高大的雙魚宮守護者，在他的身後
，是一個有如空間扭曲的區域，看來，想進入那，免不了要一場激烈
的戰鬥了！
LONG
        );

        set("exits", ([
  "east" : HOLY+"h25",
 "west" : HOLY+"h24",
        ]) );
        set("light",1);
        setup();
}
