#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIR"皇陵"HIW"入口"NOR);
        set("long", @LONG
這裡是一處荒郊野外，外傳裡面有眾多的寶物，但這只是場謠言，沒
人可證實的還有據了解，很久以前，有一個不怕死的勇士進去，但進去了
幾個月都沒出來，想必這裡面含有許多奇形怪狀的野獸吧!!還有那兒有個
老舊的石碑(stele)你大可看看!!
LONG
        );

           set("exits", ([ /* sizeof() == 1 */
            "enter" : __DIR__"room2",
            ]));
        set("item_desc",([
         "stele":"石碑上寫著: 這乃國家皇陵，沒經批準，不許\踏入
                  違者殺••無••赦••\n",
          ]));
       set("no_clean_up", 0);
        set("light", 1);
       set("valid_startroom",1);

        setup();
        replace_program(ROOM);
}


        
