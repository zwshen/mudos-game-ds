#include <room.h>
inherit ROOM;
void create()
{
 set("short","峭壁凹陷處");
 set("long",@LONG
你費了九牛二虎之力, 加上憑著高超的輕功, 終於有驚無險
的翻到了這峭壁凹進去的小平台, 深度大概只有三四尺, 一不小
心就會摔出去了, 不過高度你剛好站的進去. 你發現這邊風勢比
上面大的多了, 而且似乎都往你身上集中. 你覺得很不自在, 這
邊到底有什麼神秘的地方呢? 值得你好好推敲一番.
LONG
    );
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
