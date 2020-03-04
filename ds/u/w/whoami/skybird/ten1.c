#include <room.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","山壁旁");

 set("long",@LONG
你身旁就是通向山口的峭壁, 往北則通向十萬大山中次高
的千嶙峰, 你發現你的四周都是一些陡峭的岩石, 唯一的出路
似乎只有往北走了.
LONG
    );
 set("exits",([ "northup":__DIR__"ten2",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

