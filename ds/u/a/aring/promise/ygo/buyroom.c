// code by blueshadow
// code by blueshadow
// Recode by Promise
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"[武藤遊戲店] "HIW"戰鬥怪獸卡專賣店"NOR);
        set("long","
這裡是武藤家的玩具店，裡頭有許\多現代所流行的遊戲與玩具，
當然有現今最流行的戰鬥怪獸卡。如果需要購買的話，請看下牆壁
上貼的海報(post)，裡頭有些相關資料可以參考。
\n");
        set("item_desc", ([ /* sizeof() == 1 */
"post" : HIW"
怪獸卡添購守則：

1 .請先買個空牌組
2 .然後解個小Quest，完成後武藤雙六會給你獎勵。
3 .也可以不解Quest，直接花錢添購戰鬥怪獸卡包。
4 .一張卡最多只能在牌組中重複三張，一副牌組最多40張牌
\n"NOR,
]));
        set("no_fight", 1);
        set("no_kill", 1);
        set("no_clean_up", 1);
        set("exits", ([ /* sizeof() == 4 */
  "out" : "/open/world1/tmr/area/hotel", 
  "east" : __DIR__"playroom_1",]));
        setup();
}


