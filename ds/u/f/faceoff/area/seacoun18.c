#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","漁網店");
set("long",@LONG
這裡掛著各式各樣的漁網, 不過自從無砂鎮改成商業港後
, 這類的店舖已經很少很少囉! 這裡還能夠生存下來, 主要是
因為店主包達廷是這個鎮上少有的健談高手, 而來這裡聊天
總是要買一些漁網才行, 因此才能夠在今天把無砂鎮殘存的
漁網生意通通包下, 勉強度日吧?
LONG
    );
 set("exits",(["east":__DIR__"seacoun6",
]));
 set("objects", ([__DIR__"npc/bou" :1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             