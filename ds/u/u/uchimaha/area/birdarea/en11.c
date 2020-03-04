#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","狐穴");

 set("long",@LONG
你現在來到狐狸穴的內部, 你才剛踏進這個穴裡, 
你就被血腥味搞得快要吐出來了, 突然有一群眼睛血紅
的狐狸朝你衝過來, 不分青紅皂白的往你這咬來, 你只
好硬著頭皮跟他們戰鬥了。
 
LONG
    );
 
 set("exits",(["out":__DIR__"en10",
               "north":__DIR__"en12",
           ]));
 set("objects",([__DIR__"npc/fox3" : 3,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
