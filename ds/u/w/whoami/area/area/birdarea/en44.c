#include <room.h>
inherit ROOM;
void create()
{
 set("short","小路");
 set("long",@LONG
你繼續往東走, 這裡的景物大概沒什麼變化, 你覺
得有些無聊, 不知不覺醒吹起口哨起來了, 你吹起了大
家耳熟能詳的兒歌, 你現在才看到這條路一直通往北方
不遠處.
LONG
    );
 
 set("exits",(["north":__DIR__"en45",
               "west":__DIR__"en43",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
