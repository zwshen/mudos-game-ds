#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
你又往上爬了不少了距離, 你看了看四周, 你發現
你已經在雲層之上了, 溫暖的陽光, 往你身上直撲過來,
清新的空氣, 讓你所有的壓力獲得釋放, 你不禁羨慕起
住在這峭壁上的人。

LONG
    );
 
 set("exits",(["up":__DIR__"bird6",
               "down":__DIR__"bird4",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
