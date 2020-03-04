#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
你來到一處峭壁底下, 你抬頭往天上看, 峰頂直達
雲宵之上, 你實在無法用眼測出這個峭壁到底有多高, 
假如你自認為自己輕功不錯, 你就上去看看吧, 在這旁
邊有一個巨岩(rock), 上面似乎刻著一些字....忽然你
聽到峭壁頂上有人在長嘯, 於是你決定上去看看....

LONG
    );
 set("item_desc",([
        "rock":"你朝這巨岩看了看, 發現上面有四個血紅的大字,\n
          "HIR"絕  世  峭  壁"NOR"\n
     你不禁想見識看看寫這個字的主人.\n",
     ]));
 set("exits",(["south":__DIR__"en45",
     ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();
        if (arg != "絕世峭壁") return 0;
        
        message_vision("只見$N手、足並用，慢慢地爬上了峭壁。\n" ,me);
        me->move(__DIR__"bird2.c");
        tell_room(environment(me),me->query("name")+"氣喘噓噓地爬了上來。n",me);
        return 1;
}          
