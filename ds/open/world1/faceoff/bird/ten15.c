#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","望月崖");

 set("long",@LONG
這裡就是久負盛名的望月崖, 你舉目一望, 藍的是天, 綠的
是底下的東北澤林, 景色相當美麗, 住在山上的情侶在圓月之夜
便成雙成對的到這裡來談情, 久而久之就漸漸的出名了, 這裡的
地勢已經比其它的山低了很多, 使你可以很清楚的觀察到底下獵
狐村的一舉一動.
LONG
    );
 set("exits",([ "southeast":__DIR__"ten14",
    ]));
 set("item_desc",([
        "東北澤林":"一片綠油油的森林, 令你有想從這跳下去(jump down)的衝動!.\n"
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
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
      if (arg != "down") return 0;
      message_vision("$N不知死活的向下跳去!!\n"  ,me);
      me->move( "/open/world1/uchimaha/bird/village17");
      return 1;
      }
