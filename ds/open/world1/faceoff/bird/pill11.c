#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
這裡是天梟冶藥一派的東邊部份, 從這裡終於可以看到柱
子的背面, 你發現原來柱子的背面是一個凹洞, 裡面嵌著一個
大大的梟像供來人祭拜, 你才恍然大悟, 天梟本來就是一個教
嘛....
LONG
    );
 set("exits",([ "northwest":__DIR__"pill7",
		"south":__DIR__"pill13",
    ]));
 set("item_desc",([
        "柱子":"一根大大的柱子, 你發現似乎可以跳(jump)上去....\n"
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
      object me;
      me=this_player();
      if (arg != "柱子") return 0;
      message_vision(HIY"$N在柱子上跳上跳下...\n"NOR  ,me);
      tell_object(me,HIY"你終於跳到柱頂了!\n"NOR);
      me->move(__DIR__ "floor1");   
      return 1;
      }