#include <room.h>
inherit ROOM;
void create()
{
 set("short","神秘洞窟");
 set("long",@LONG
好不容易解決了那堆大石, 你來到了一個幽暗的洞窟之中, 洞窟之
中只有一盞快用光的油燈, 你看到了一塊大石之上還坐了一名側著你的
老者, 手杵著劍, 頭靠著手. 後方的石壁上可以清楚的看見還刻了首詩:

                殺   持   獨   惟
                聲   劍   在   憾
                轟   浴   江   餘
                傳   血   湖   我
                九   斬   步   稱       絕
                千   荊   紅   無       世
                里   棘   塵   敵       間
                                        
                                        題
                                        
寫這首詩的人真是自大至極! 難不成是這老傢伙? 你正不斷的思索著..
LONG
    );
 set("exits",([ "out":__DIR__"jungle18",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}