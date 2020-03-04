#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","市集");
set("long",@LONG
你步行至此, 人潮已經減少許多, 不過還是有些許的旅客到
這裡看一看, 你發現在你的南邊有幾個寥寥無幾的石屋, 看來有
些時日沒有主人囉!
LONG
    );
 set("exits",([ "west":__DIR__"seacoun26",
		"east":__DIR__"seacoun24",
]));
 set("item_desc",([
        "石屋":"一排小小的石屋, 你可以走進去(enter)看看.\n"
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            

void init()
{
       add_action("typeenter","enter");
}
     int typeenter(string arg)
{
        object me,obj;
        me=this_player();
	obj=this_object();
        if(arg != "石屋") return 0;
        message_vision("$N矮身進入了石屋.\n",me);
	me->move(__DIR__ "seacoun28");
        return 1;
}
