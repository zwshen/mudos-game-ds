#include <room.h>
inherit ROOM;
void create()
{
 set("short","右側平臺");
 set("long",@LONG
這邊就比較偏遠了一點, 若你從這個角度往山巔看去, 你
可以發現峭壁之上似乎有一個亭子. 不過要怎麼通往那個亭子,
確實是一個大問題..  
LONG
    );
 set("exits",(["west":__DIR__"inroom37",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
