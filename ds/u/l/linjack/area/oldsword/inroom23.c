#include <room.h>
inherit ROOM;
void create()
{
 set("short","疾風門賓室");
 set("long",@LONG
這間是疾風門的賓室, 裡面也裝飾的比較簡樸一點, 這邊似乎
有放了個蚊香, 你感覺到有一點刺鼻的煙味. 大會結束後這邊現在
也沒有疾風門較高層的人物逗留在此, 大都先回去了, 只留下了四
名門人在此, 他們一邊喝著茶, 一邊討論著武林大會的一些事情.
LONG
    );
 set("exits",([ "south":__DIR__"inroom15",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
