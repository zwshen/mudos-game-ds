#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"狹道"NOR);

 set("long",@LONG
這依然是在十萬大山壑谷中的一條順地勢開闢的小路, 
其實這根本是一條不是路的小路, 總共約只有三寸寬, 你
心中實在懷疑會有哪個瘋子來走這種一失足成千古恨的小
路?....
LONG
    );
 set("exits",([ "west":__DIR__"ten_mountain5", 
                "south":__DIR__"ten_mountain7",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
