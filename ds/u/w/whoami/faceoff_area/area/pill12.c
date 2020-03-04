#include <ansi.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
這裡是天梟冶藥一派的東邊部份, 從這再往南走就是天梟
冶藥一派的藥材室, 往北則是正廳, 通常掌門人趙長孫就是在
那接待客人, 而從這一樣可以看見那根大柱子.
LONG
    );
 set("exits",([ "southwest":__DIR__"pill8",
		"north":__DIR__"pill13",
    ]));
 set("item_desc",([
        "柱子":"一根大大的柱子, 你發現似乎可以跳上去....\n"
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
      message_vision(HIY"$N屏住氣息, 縱身躍上柱子!\n"NOR  ,me);
      tell_object(me,HIY"你終於躍上柱頂了!\n"NOR);
      me->move(__DIR__ "floor1");   
      }
